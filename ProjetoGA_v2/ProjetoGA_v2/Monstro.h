#pragma once
#include "Personagem.h"
#include <string>
#include "util.h"
using namespace std;

enum NomesMonstros {
	Dragao, MonstroIndefinido
};

class Monstro : public Personagem
{
public:
	Monstro();
	Monstro(NomesMonstros nome);
	Monstro(NomesMonstros nome, int habilidade, int energia , int sorte, int provisao, int tesouro);
	void montaMonstro(NomesMonstros nomeArquivo);

	void setProvisao(int);
	void setTesouro(int);

	int getProvisao();
	int getTesouro();

	string getStringMonstro(NomesMonstros);
	NomesMonstros getNomeMonstro(string);
	string getArquivoMonstro(NomesMonstros);
private:
	NomesMonstros nome;
	int provisao;
	int tesouro;
	Item* pItem;
};

