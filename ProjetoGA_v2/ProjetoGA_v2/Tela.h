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
	void exibir();
	void pressioneParaVoltar();
	int pressioneAcao();
	void setCena(Cena*);
private:
	Cena* cena;
};

