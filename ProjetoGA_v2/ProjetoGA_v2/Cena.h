#pragma once
#include "Item.h"
#include <string>
#include <vector>
#include "util.h" 

using namespace std;

class Cena
{
public:
	Cena();
	Cena(string nomeArquivo);
	void montaCena();

	bool temItem();
	Item* getItem();
	bool temBatalha();
	void setArquivoCena(string);

	string getNomeArquivo();
	string getTexto();
	string getArqMonstro();
	vector<string> getEscolhas();
private:
	string nomeArquivo;
	bool bItem;
	bool bBatalha;
	string texto;
	Item* pItem;
	vector<string> escolhas;
	string arqMonstro;
};

