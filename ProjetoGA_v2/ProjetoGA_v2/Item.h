#pragma once
#include <string>
using namespace std;

enum TiposDeItens {
	Porrete,
	LivroDeFeiticos
};

class Item
{
public:
	Item();
	Item(string nome, string tipo, bool combate, int FA, int dano);

	string getNome();
	string getTipo();
	bool getCombate();
	int getFA();
	int getDano();

	void setNome(string nome);
	void setTipo(string tipo);
	void setCombate(bool combate);
	void setFA(int FA);
	void setDano(int dano);

private:
	string nome;
	string tipo;
	bool combate;
	int FA;
	int dano;
};