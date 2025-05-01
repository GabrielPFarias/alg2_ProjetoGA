#include "Jogo.h"

Jogo::Jogo() {
	setlocale(LC_ALL, "pt_BR.UTF-8");// Para usar acentos e cedilha no terminal
	cenaAtual = new Cena;
	jogador = new Jogador;
	batalha = new Batalha;
}
Jogo::Jogo(Jogador* jogador, Cena* cenaAtual) {
	this->jogador = jogador;
	this->cenaAtual = cenaAtual;
	batalha = new Batalha;
	setlocale(LC_ALL, "pt_BR.UTF-8"); // Para usar acentos e cedilha no terminal
}
void Jogo::iniciaJogo() {
	setlocale(LC_ALL, "pt_BR.UTF-8"); // Para usar acentos e cedilha no terminal
	//cenaAtual = new Cena("arquivos/tela_abertura.txt");
	Tela tela(cenaAtual);
	//Jogador jogador;
	bool fimDeJogo = false;

	cenaAtual->setArquivoCena("arquivos/tela_abertura.txt");
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
		jogador->imprimirInventario();
		pressiona_prosseguir();
		cenaAtual->setArquivoCena("arquivos/cenas/1.txt");
		break;
	case 3:
		break;
	case 4:
		break;
	}
	while (fimDeJogo == false) {
		tela.exibirTexto();
		if (fimDeJogo = cenaAtual->temFim()) {
			break;
		}
		else {
			if (cenaAtual->temBatalha()) {
				pressiona_prosseguir();
				limpar_tela();
				//batalha(cenaAtual->getMonstro(), &jogador);
				//batalha.iniciaBatalha();
			}
			else {
				tela.exibirEscolhas();
				if (cenaAtual->temItem()) {
					jogador->addItemInventario(cenaAtual->getItem());
				}
				string escolha = pressiona_escolha();
				if (escolha == "e") {
					jogador->imprimirInventario();
					pressiona_prosseguir();
				}
				else if (escolha == "s") {
					salvar();
					break;
				}
				else {
					cenaAtual->getEscolhaJogador(escolha);
				}

			}
		}
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
	
}

string Jogo::selecionaSave() {
	string nomeSave;
	vector<string> sSaves= getListaJogosSalvos();
	if (sSaves == "") {
		cout << 
	}
	return nomeSave;
}
vector<string> Jogo::getListaJogosSalvos(){
	for (size_t i = 0; i < sSaves.size(); ++i) {
		n
			cout << i + 1 << ". " << sSaves[i] << endl;
	}
}
