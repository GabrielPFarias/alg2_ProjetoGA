#pragma once
#include<string>
#include "Jogador.h"
#include "cena.h"
#include "Tela.h"

using namespace std;

class Jogo
{
public:
	Jogo();
	Jogo(Jogador* jogador, Cena* cena);
	void iniciaJogo();

private:
	Jogador* jogador;
	Cena* cena;
	bool end;
};

