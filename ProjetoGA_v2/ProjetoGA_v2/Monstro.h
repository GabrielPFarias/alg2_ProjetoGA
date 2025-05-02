#pragma once
#include "Personagem.h"
#include <string>
#include "util.h"
#include <algorithm>
#include <cctype>  
using namespace std;

enum NomesMonstros {
	Dragao, Aranha, Esqueleto, Fantasma, Lobisomem, MonstroIndefinido
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

	NomesMonstros getNome();
	int getProvisao();
	int getTesouro();
	Item* getItem();

	string getStringMonstro(NomesMonstros);
	NomesMonstros getNomeMonstro(string);
	string getArquivoMonstro(NomesMonstros);
private:
	NomesMonstros nome;
	int provisao;
	int tesouro;
	Item* pItem;
};

