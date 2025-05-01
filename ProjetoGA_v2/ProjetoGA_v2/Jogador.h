#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Inventario.h"
#include "Personagem.h"
#include "util.h"
#include "Item.h"

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
	Jogador(string nome, int habilidade, int energia, int sorte, Classe classe, Inventario* inventario);
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

	void addItemInventario(Item*);
	void imprimirInventario();
	void imprimirInventarioResumido();

	Classe escolhaMagoGuerreiro(string escolha);
	string getTodosDados();
private:
	string nome;
	Classe classe;
	Inventario* inventario;
	bool magiaLiberada;
};

