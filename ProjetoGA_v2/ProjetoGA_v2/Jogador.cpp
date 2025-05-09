#include "Jogador.h"
#include <iomanip>
#include <locale>

Jogador::Jogador() 
	: nome(""), Personagem(0, 0, 0), classe(Indefinido), inventario(nullptr) {
	setlocale(LC_ALL, "pt_BR.UTF-8");
}

Jogador::Jogador(string nome, int habilidade, double energia, int sorte, Classe classe, Inventario* inventario)
	: nome(nome), Personagem(habilidade, energia, sorte), classe(classe), inventario(inventario) {
	setlocale(LC_ALL, "pt_BR.UTF-8");
}

int pedirValor(string atributo, int* pontosRestantes, int minimoDepois) {
	int valor;
	cout << u8"\nVocê tem: " << *pontosRestantes << " pontos restantes.\nInsira o valor para " << atributo << ": ";
	cin >> valor;
	while (*pontosRestantes - valor < minimoDepois) {
		cout << u8"Valor inválido. Tente novamente: ";
		cin >> valor;
	}
	*pontosRestantes = *pontosRestantes - valor;
	//limpar_tela();
	return valor;
}

string Jogador::getNome() {
	return nome;
}
Classe Jogador::getClasse() {
	return classe;
}
Inventario* Jogador::getInventario(){
	return inventario;
}
bool Jogador::getMagiaLiberada() {
	atualizaMagiaLiberada();
	return magiaLiberada;
}
void Jogador::setNome(string nome) {
	this->nome = nome;
}
void Jogador::setClasse(Classe classe) {
	this->classe = classe;
}
void Jogador::setInventario(Inventario* inventario) {
	this->inventario = inventario;
}
void Jogador::atualizaMagiaLiberada() {
	if (classe == Mago) {
		magiaLiberada = true;
	}
	else if (classe == Guerreiro) {
		if (inventario->temItem(LivroDeFeiticos)) {
			magiaLiberada = true;
		}
		else {
			magiaLiberada = false;
		}
	}
}
void Jogador::addItemInventario(Item* item) {
	inventario->addItem(item);
}
void Jogador::rmItemInventario(Item* item) {
	inventario->rmItem(item);
}
bool Jogador::temItem(NomesItens nomeItem) {
	return inventario->temItem(nomeItem);
}
void Jogador::inicializaJogador() {
	setlocale(LC_ALL, "pt_BR.UTF-8");
	inventario = new Inventario();
	limpar_tela();
	cout << u8"Deseja configurar seu personagem manualmente ou definí-lo automaticamente de forma aleatória?" << endl;
	cout << u8"\n- (1) Manual\n- (2) Automático" << endl;
	string escolha = pressiona_escolha();
	while (escolha != "1" && escolha != "2") {
		cout << u8"Valor inválido. Insira novamente:  " << endl;
		escolha = pressiona_escolha();
	}
	if (escolha == "1") {
		defineAtributos();
	}
	else {
		defineAtributosAleatorios();
	}
	
	atualizaMagiaLiberada();
}
void Jogador::addProvisao(int provisao) {
	inventario->addProvisao(provisao);
}
void Jogador::rmProvisao(int provisao) {
	inventario->rmProvisao(provisao);
}
void Jogador::addTesouro(int tesouro) {
	inventario->addProvisao(tesouro);
}
void Jogador::rmTesouro(int tesouro) {
	inventario->rmTesouro(tesouro);
}
Classe Jogador::escolhaMagoGuerreiro(string escolha) {
	while (escolha != "1" && escolha!= "2") {
		cout << u8"\nValor inválido. Enive outro." << endl;
		escolha = pressiona_escolha();
	}
	if (escolha == "1") {
		Item* itemPadrao = new Item(Feitico);
		inventario->addItem(itemPadrao);
		return Mago;
	}
	else if (escolha == "2") {
		Item* itemPadrao = new Item(Porrete);
		inventario->addItem(itemPadrao);
		return Guerreiro;
	}
}
void Jogador::imprimirInventario() {
	setlocale(LC_ALL, "pt_BR.UTF-8"); // Para usar acentos e cedilha no terminal
	limpar_tela();
	// Formatação com setw para alinhar as colunas
	cout << "Digite 'e' sempre que quiser abrir o inventario\n" << endl;
	cout << left << setw(20) << "NOME DO JOGADOR:" << setw(20) << getNome() << endl;
	cout << left << setw(20) << "CLASSE:" << setw(20)
		<< (classe == Mago ? "MAGO" : (classe == Guerreiro ? "GUERREIRO" : "INDEFINIDO")) << endl;
	cout << left << setw(20) << "HABILIDADE:" << setw(20) << getHabilidade() << endl;
	cout << left << setw(20) << "ENERGIA:" << setw(20) << getEnergia() << endl;
	cout << left << setw(20) << "SORTE:" << setw(20) << getSorte() << endl;

	// Adicionando uma linha em branco entre as seções
	cout << endl;

	// Imprimir o inventário
	cout << left << setw(20) << u8"INVENTÁRIO" << endl;
	cout << "  Itens:" << endl;

	// Se o inventário estiver vazio
	if (inventario->getItens().empty()) {
		cout << "Nenhum item no inventário." << endl;
	}
	else {
		// Caso contrário, imprimir os itens com formatação
		for (Item* item : inventario->getItens()) {
			cout << left << setw(20) << "    Nome:" << setw(30) << item->getStringNomesItem(item->getNome()) << endl;
			cout << left << setw(20) << "    Tipo:" << setw(30) << item->getTipoDeItensSignificado(item->getTipo()) << endl;
			cout << left << setw(20) << "    Combate:" << setw(30) << (item->getCombate() ? "Sim" : u8"Não") << endl;
			cout << left << setw(20) << "    FA:" << setw(30) << item->getFA() << endl;
			cout << left << setw(20) << "    Dano:" << setw(30) << item->getDano() << endl;
			cout << endl;  // Linha em branco entre os itens
		}
	}

	// Imprimir provisão e tesouro com formatação
	cout << left << setw(20) << u8"PROVISÃO:" << setw(20) << inventario->getProvisao() << endl;
	cout << left << setw(20) << "TESOURO:" << setw(20) << inventario->getTesouro() << endl;
}
void Jogador::imprimirInventarioResumido() {
	inventario->imprimirResumido();
}
void Jogador::defineAtributos() {

	limpar_tela();

	cout << "Escolha um nome para seu personagem. Seja criativo!" << endl;
	cin >> nome;

	limpar_tela();

	string conteudo;

	conteudo = acessaArquivo("arquivos/inicializacao_jogador_classe.txt");
	cout << conteudo << endl;
	classe = escolhaMagoGuerreiro(pressiona_escolha());

	limpar_tela();
	conteudo = acessaArquivo("arquivos/inicializacao_jogador_atributos.txt");
	cout << conteudo << endl;
	int pontosRestantes = 12;
	habilidade = pedirValor("HABILIDADE", &pontosRestantes, 2) + 6;
	energia = pedirValor("ENERGIA", &pontosRestantes, 1) + 12;
	sorte = pedirValor("SORTE", &pontosRestantes, 0) + 6;
}
void Jogador::defineAtributosAleatorios() {
	limpar_tela();
	int pontosRestantes = 12;
	cout << "Escolha um nome para seu personagem. Seja criativo!" << endl;
	cin >> nome;
	classe = geraClasseAleatoria();
	habilidade = geraValorAleatorio(0, &pontosRestantes) +6;
	energia = geraValorAleatorio(0, &pontosRestantes)+12;
	sorte = geraValorAleatorio(0, &pontosRestantes)+6;
}
Classe Jogador::geraClasseAleatoria() {
	int max = 2;
	int numero = geraValorAleatorio(1, &max);
	return escolhaMagoGuerreiro(to_string(numero));
}
string Jogador::getTodosDados() {
	string conteudo = "";
	string sClasse = "";
	if (classe == Mago) {
		sClasse = "Mago";
	}
	else {
		sClasse = "Guerreiro";
	}
	if (inventario)
		conteudo = nome + ";" + sClasse + ";" + to_string(getHabilidade()) + ";" + to_string(getEnergia()) + ";"+ to_string(getSorte()) + ";" + inventario->getTodosDados();
	else
		conteudo = nome + ";" + sClasse + ";(sem inventário)";
	return conteudo;
}

Classe Jogador::getNomeClasse(string sNome) {
	if (sNome == "Mago" || sNome == "mago" || sNome=="MAGO") return Mago;
	if (sNome == "Guerreiro" || sNome == "guerreiro" || sNome == "GUERREIRO") return Guerreiro;
}
int Jogador::geraValorAleatorio(int min, int* max) {
	random_device rd;
	mt19937 gen(rd());

	uniform_real_distribution<> dis(min, *max);

	int numero = dis(gen);
	*max = *max - numero;
	return numero;
}