#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Inventario.h"
#include "Personagem.h"
#include "util.h"

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

	Classe getClasse();
	Inventario* getInventario();
	bool getMagiaLiberada();

	void setClasse(Classe);
	void setInventario(Inventario*);
	void atualizaMagiaLiberada();

	void inicializaJogador();
	void defineAtributos();

private:
	Classe classe;
	Inventario* inventario;
	bool magiaLiberada;
};

