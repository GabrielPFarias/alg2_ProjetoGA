#pragma once
#include "Personagem.h"
#include <string>
#include "util.h"
using namespace std;

class Monstro : public Personagem
{
public:
	Monstro();
	Monstro(string nome, int habilidade, int energia , int sorte, int provisao, int tesouro);
	void montaMonstro(string nomeArquivo);

	void setProvisao(int);
	void setTesouro(int);

	int getProvisao();
	int getTesouro();
private:
	int provisao;
	int tesouro;
	Item item;
};

