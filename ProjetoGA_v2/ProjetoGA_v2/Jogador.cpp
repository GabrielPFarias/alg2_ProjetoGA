#include "Jogador.h"

Jogador::Jogador() 
	: Personagem("", 0, 0, 0), classe(Indefinido), inventario(nullptr) {}

Jogador::Jogador(string nome, int habilidade, int energia, int sorte, Classe classe, Inventario* inventario)
	: Personagem(nome, habilidade, energia, sorte), classe(classe), inventario(inventario) {}


Classe Jogador::getClasse() {
	return classe;
}
Inventario* Jogador::getInventario(){
	return inventario;
}
bool Jogador::getMagiaLiberada() {
	return magiaLiberada;
}
void Jogador::setClasse(Classe classe) {
	this->classe = classe;
}
void Jogador::setInventario(Inventario* inventario) {
	this->inventario = inventario;
}
void Jogador::atualizaMagiaLiberada() {
	/*if (classe == Mago) {
		magiaLiberada = true;
	}
	else if (classe == Guerreiro) {
		if (inventario->temItemMagico()) {
			magiaLiberada = true;
		}
		else {
			magiaLiberada = false;
		}
	}
	*/
}

void Jogador::inicializaJogador() {
	
	defineAtributos();

	Inventario inventarioJogador;
	inventario = &inventarioJogador;

	atualizaMagiaLiberada();
}

Classe escolhaMagoGuerreiro(string escolha) {
	if (escolha == "1") {
		return Mago;
	}
	else if (escolha == "2") {
		return Guerreiro;
	}
}

void Jogador::defineAtributos() {
	string conteudo = acessaArquivo("arquivos/inicializacao_jogador.txt");
	vector<string> partesConteudo = split(conteudo, '#');

	cout << partesConteudo[0] << endl;
	classe = escolhaMagoGuerreiro(pressiona_escolha());

	for (int i = 1; i < partesConteudo.size(); i++) {
		cout << partesConteudo[i] << endl;
		pressiona_prosseguir();
		system("cls");
	}

	int pontosRestantes = 12;
	int valor = 0;

	cout << "Você tem:" << pontosRestantes << " restantes \nInsira o valor para HABILIDADE: " << endl;
	cin >> valor;
	while (pontosRestantes - valor < 2) {
		cin >> valor;
		if (pontosRestantes - valor < 2) {
			cout << "Valor inválido" << endl;
		}
	}
	setHabilidade(valor);
	pontosRestantes = pontosRestantes - valor;
	system("cls");

	cout << "Você tem:" << pontosRestantes << " restantes \nInsira o valor para ENERGIA: " << endl;
	cin >> valor;
	while (pontosRestantes - valor < 1) {
		cin >> valor;
		if (pontosRestantes - valor < 1) {
			cout << "Valor inválido" << endl;
		}
	}
	pontosRestantes = pontosRestantes - valor;
	setEnergia(valor);
	system("cls");

	cout << "Você tem:" << pontosRestantes << " restantes \nInsira o valor para SORTE: " << endl;
	cin >> valor;
	while (pontosRestantes - valor < 0) {
		cin >> valor;
		if (pontosRestantes - valor < 0) {
			cout << "Valor inválido" << endl;
		}
	}
	pontosRestantes = pontosRestantes - valor;
	setSorte(valor);
	system("cls");
}