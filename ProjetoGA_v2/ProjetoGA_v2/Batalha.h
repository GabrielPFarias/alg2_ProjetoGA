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
	double geraValorAleatorio(double, double);
	void geraMultiplicador();

	void perguntaUsarInventario();
	bool getResultado();
	void usarItem(Item* pItem);
private:
	void turno();
	Monstro* monstro;
	Jogador* jogador;
	double multiplicador;
	bool resultado;
};

