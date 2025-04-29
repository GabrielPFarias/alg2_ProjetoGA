#pragma once
#include "Cena.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Tela
{
public:
	Tela();
	Tela(Cena* cena);
	void exibirTexto();
	void exibirEscolhas();

	void pressioneParaVoltar();
	int pressioneAcao();
	void setCena(Cena*);
private:
	Cena* cena;
};

