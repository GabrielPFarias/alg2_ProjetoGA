#pragma once
#include<string>
#include <locale>
#include "Jogador.h"
#include "cena.h"
#include "Tela.h"
#include "Batalha.h"

using namespace std;

class Jogo
{
public:
	Jogo();
	Jogo(Jogador* jogador, Cena* cena);
	void iniciaJogo();
	void salvar();
private:
	Jogador* jogador;
	Cena* cena;
	bool end;
};

