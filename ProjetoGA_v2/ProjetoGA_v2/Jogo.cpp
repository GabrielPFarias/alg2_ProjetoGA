#include "Jogo.h"

Jogo::Jogo() {
	setlocale(LC_ALL, "pt_BR.UTF-8");// Para usar acentos e cedilha no terminal
	cenaAtual = new Cena;
	jogador = new Jogador;
}
Jogo::Jogo(Jogador* jogador, Cena* cenaAtual) {
	this->jogador = jogador;
	this->cenaAtual = cenaAtual;
	setlocale(LC_ALL, "pt_BR.UTF-8"); // Para usar acentos e cedilha no terminal
}
void Jogo::iniciaJogo() {
	setlocale(LC_ALL, "pt_BR.UTF-8"); // Para usar acentos e cedilha no terminal
	Tela tela(cenaAtual);
	bool fimDeJogo = false;
	cenaAtual->setArquivoCena("arquivos/tela_abertura.txt");
	bool itemAdicionado = false;

	while (fimDeJogo == false) {
		tela.exibirTexto();
		switch (stoi(pressiona_escolha())) {
		case 1:
			jogador->inicializaJogador();
			jogador->imprimirInventario();
			pressiona_prosseguir();
			cenaAtual->setArquivoCena("arquivos/cenas/1.txt");
			break;
		case 2:
			carregar();
			break;
		case 3:
			cenaAtual->setArquivoCena("arquivos/tela_creditos.txt");
			tela.exibirTexto();
			pressiona_prosseguir();
			cenaAtual->setArquivoCena("arquivos/tela_abertura.txt");
			break;
		case 4:
			limpar_tela();
			fimDeJogo = true;
			break;
		}
		while (1) {
			if (cenaAtual->getNomeArquivo() == "arquivos/tela_abertura.txt") {
				limpar_tela();
				break;
			}
			tela.exibirTexto();
			fimDeJogo == cenaAtual->temFim();
			if (fimDeJogo) {
				break;
			}
			else {
				if (cenaAtual->temBatalha()) {
					pressiona_prosseguir();
					limpar_tela();
					batalha = new Batalha(cenaAtual->getMonstro(), jogador);
					batalha->iniciaBatalha();
					string sProximaCena = "";
					if (batalha->getResultado()) {
						sProximaCena = "1"; //ganhou a batalha
						recebeItens();
					}
					else {
						sProximaCena = "2"; //perdeu a batalha
					}
					cenaAtual->getProximaCena(sProximaCena);
				}
				else {
					tela.exibirEscolhas();
					if (cenaAtual->temItem() && itemAdicionado == false) {
						jogador->addItemInventario(cenaAtual->getItem());
						itemAdicionado = true;
					}
					string escolha = pressiona_escolha();
					if (escolha == "e") {
						jogador->imprimirInventario();
						pressiona_prosseguir();
					}
					else if (escolha == "s") {
						salvar();
						fimDeJogo = true;
						break;
					}
					else {
						cenaAtual->getProximaCena(escolha);
						itemAdicionado = false;
					}
				}
			}
		}
		//break;
	}
}
void Jogo::salvar() {
	setlocale(LC_ALL, "pt_BR.UTF-8"); // Para usar acentos e cedilha no terminal
	limpar_tela();
	cout << u8"Qual nome você deseja dar a esse save?" << endl;
	string nomeJogo;
	cin >> nomeJogo;
	while (verificaArquivosExistentes(nomeJogo)) {
		cout << u8"\nJá existe um save com esse nome. Escolha outro:  ";
		cin >> nomeJogo;
	}
	ofstream arquivoSave("arquivos/saves/" + nomeJogo + ".txt");
	arquivoSave << cenaAtual->getNomeArquivo();
	arquivoSave << "#";
	arquivoSave << jogador->getTodosDados();
}

bool Jogo::verificaArquivosExistentes(std::string nomeArquivo) {
	ifstream arquivo("arquivos/saves/" + nomeArquivo + ".txt");
	return arquivo.good();
}

void Jogo::carregar() {
	limpar_tela();
	string save = selecionaSave();
	if (save == "") {
		cout << "Sem jogos salvos." << endl;
		pressiona_prosseguir();
		return;
	}
	else if (save == "Voltar para página anterior.txt") {
		limpar_tela();
		return;
	}
	string conteudo = acessaArquivo("arquivos/saves/"+save);
	montaJogo(conteudo);
}

string Jogo::selecionaSave() {
	string nomeSave;
	vector<string> lSaves = getListaJogosSalvos();
	lSaves.push_back("Voltar para página anterior");
	if (lSaves.empty()) {
		return "";
	}
	cout << "Escolha um dos salvamentos abaixo:\n" << endl;
	size_t i;
	for ( i = 0; i < lSaves.size()-1 ; i++) {
		size_t pos = lSaves[i].find(".txt");
		if (pos != std::string::npos) {
			lSaves[i].erase(pos, 4);  // 4 é o tamanho de ".txt"
		}
		cout << "(" << i + 1 << ") " << lSaves[i] << "\n";
	}

	cout << "\n(" << lSaves.size() << ") " << lSaves[i] << "\n";
	string escolha = pressiona_escolha();
	while (1) {
		if (stoi(escolha) < 0 || stoi(escolha) > (lSaves.size())){
			cout << "Escolha inválida, insira novamente:   " << endl;
			escolha = pressiona_escolha();
		}
		else {
			break;
		}
	}
	nomeSave = lSaves[stoi(escolha)-1];
	return nomeSave + ".txt";
}
vector<string> Jogo::getListaJogosSalvos(){
	vector<string> listaArquivos;
	string caminho = "arquivos/saves";

	for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(caminho)) {
		if (entry.is_regular_file()) {
			listaArquivos.push_back(entry.path().filename().string());
		}
	}
	return listaArquivos;
}
void Jogo::montaJogo(string conteudo){
	vector<string> partesConteudo = split(conteudo, '#');

	string sCena = partesConteudo[0];
	string sJogador = partesConteudo[1];

	vector<string> partesJogador = split(sJogador, ';');

	jogador->setNome(partesJogador[0]);
	jogador->setClasse(jogador->getNomeClasse(partesJogador[1]));
	jogador->setHabilidade(stoi(partesJogador[2]));
	jogador->setEnergia(stoi(partesJogador[3]));
	jogador->setSorte(stoi(partesJogador[4]));
	string sInventario = partesJogador[5];

	vector<string> partesInventario = split(sInventario, '.');

	int provisao = stoi(partesInventario[0]);
	int tesouro = stoi(partesInventario[1]);
	vector<string> partesItens= split(partesInventario[2], ',');

	vector<Item*> itens;
	Item* pItem;
	int i = 0; 
	for (i = 0;i < partesItens.size(); i++) {
		pItem = new Item(partesItens[i]);
		itens.push_back(pItem);
	}

	Inventario* pInventario = new Inventario(itens, provisao, tesouro);
	jogador->setInventario(pInventario);
	cenaAtual->setArquivoCena(sCena);
}
void Jogo::recebeItens() {
	Monstro* pMonstro = cenaAtual->getMonstro();

	int provisaoMonstro = pMonstro->getProvisao();
	int tesouroMonstro = pMonstro->getTesouro();
	Item* itemMonstro = pMonstro->getItem();

	jogador->addProvisao(provisaoMonstro);
	jogador->addTesouro(tesouroMonstro);
	jogador->addItemInventario(itemMonstro);
}