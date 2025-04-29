#pragma once
#include "Monstro.h"
#include "Jogador.h"
#include <random>
#include <iostream>
#include <iomanip>

using namespace std;

class Batalha
{
public:
	Batalha();
	Batalha(Monstro* monstro, Jogador* jogador);

	void iniciaBatalha();

	bool bTestarSorte();
	double testarSorte();
	void geraMultiplicador();

	void perguntaUsarInventario();
private:
	Monstro* monstro;
	Jogador* jogador;
	double multiplicador;
};

