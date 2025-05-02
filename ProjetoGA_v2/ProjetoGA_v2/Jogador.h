#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Inventario.h"
#include "Personagem.h"
#include "util.h"
#include "Item.h"
#include <random>
#include <iostream>
#include <iomanip>

using namespace std;

enum Classe {
	Mago,
	Guerreiro,
	Indefinido
};

class Jogador : public Personagem
{
public:
	Jogador();
	Jogador(string nome, int habilidade, double energia, int sorte, Classe classe, Inventario* inventario);
	~Jogador() {
		delete inventario;
	}

	string getNome();
	Classe getClasse();
	Inventario* getInventario();
	bool getMagiaLiberada();

	void setNome(string);
	void setClasse(Classe);
	void setInventario(Inventario*);
	void atualizaMagiaLiberada();

	void inicializaJogador();
	void defineAtributos();
	void defineAtributosAleatorios();
	int geraValorAleatorio(int min, int* max);
	Classe geraClasseAleatoria();

	void addItemInventario(Item*);
	void rmItemInventario(Item*);
	void imprimirInventario();
	void imprimirInventarioResumido();
	bool temItem(NomesItens nomeItem);

	Classe escolhaMagoGuerreiro(string escolha);
	string getTodosDados();
	Classe getNomeClasse(string sNome);

	void addProvisao(int);
	void rmProvisao(int);
	void addTesouro(int);
	void rmTesouro(int);
private:
	string nome;
	Classe classe;
	Inventario* inventario;
	bool magiaLiberada;
};

