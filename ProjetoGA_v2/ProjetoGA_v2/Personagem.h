#pragma once
#include <string>
#include "Inventario.h"
using namespace std;

class Personagem
{
public:
	Personagem(string nome, int habilidade, int energia, int sorte);

    string getNome();
    int getHabilidade();
    int getEnergia();
    int getSorte();

    void setNome(string novoNome);
    void setHabilidade(int novaHabilidade);
    void setEnergia(int novaEnergia);
    void setSorte(int novaSorte);

private:
	string nome;
	int habilidade;
	int energia;
	int sorte;
};

