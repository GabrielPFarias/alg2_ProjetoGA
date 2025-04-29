#pragma once
#include "Item.h"
#include <string>
#include <vector>
#include "util.h" 
#include "Monstro.h"

using namespace std;

class Cena
{
public:
	Cena();
	Cena(string nomeArquivo);
	void montaCena();
	bool temFim();

	bool temItem();
	Item* getItem();
	bool temBatalha();
	void setArquivoCena(string);

	string getNomeArquivo();
	string getTexto();
	string getArqMonstro();
	Monstro* getMonstro();
	vector<string> getTextosEscolhas();
	vector<string> getArquivosEscolhas();

	void getEscolhaJogador(string);
private:
	string nomeArquivo;
	bool bItem;
	bool bBatalha;
	string texto;
	Item* pItem;
	vector<string> textosEscolhas;
	vector<string> arquivosEscolhas;
	string arqMonstro;
	bool bFim;
	Monstro* pMonstro;
};

