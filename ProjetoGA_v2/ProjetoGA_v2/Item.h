#pragma once
#include <string>
#include "util.h"
using namespace std;

enum NomesItens {
	Porrete,
	LivroDeFeiticos,
	Feitico,
	Chave,
	NomeIndefinido
};

enum TiposDeItens {
	C, R, W, TipoIndefinido //tipo é o tipo de item.Pode ser : c para item comum, r para armadura e w para arma
};

class Item
{
public:
	Item();
	Item(NomesItens);
	Item(NomesItens nome, TiposDeItens tipo, bool combate, int FA, int dano);

	NomesItens getNome();
	TiposDeItens getTipo();
	bool getCombate();
	int getFA();
	int getDano();

	void setNome(NomesItens nome);
	void setTipo(TiposDeItens tipo);
	void setCombate(bool combate);
	void setFA(int FA);
	void setDano(int dano);

	void montaItem(NomesItens nomeDeItem);

	string getArquivoItens(NomesItens nome);
	string getStringNomesItem(NomesItens nome);
	NomesItens getNomesItem(string nome);
	TiposDeItens getTipoDeItens(NomesItens nome);
	string getTipoDeItensSignificado(TiposDeItens tipo);

private:
	NomesItens nome;
	TiposDeItens tipo;
	bool combate;
	int FA;
	int dano;
};