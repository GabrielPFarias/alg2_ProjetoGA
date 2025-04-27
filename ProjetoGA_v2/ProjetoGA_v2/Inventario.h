#pragma once
#include "Item.h"
#include <vector>
#include <string>
using namespace std;

class Inventario
{
public:
	Inventario();
	Inventario(vector<Item*> itens, int provisao, int tesouro);
	
	vector<Item*> getItens();
	int getProvisao();
	int getTesouro();

	void setProvisao(int);
	void setTesouro(int);

	void addItem(Item*);
	void rmItem(Item*);
	void addProvisao(int);
	void rmProvisao(int);
	void addTesouro(int);
	void rmTesouro(int);

private:
	vector<Item*> itens;
	int provisao;
	int tesouro;
};

