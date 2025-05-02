#pragma once
#include <string>
#include "util.h"
#include <algorithm>
#include <cctype> 
using namespace std;

enum NomesItens {
	Porrete,
	LivroDeFeiticos,
	Feitico,
	Chave,
	Amuleto,
	AdagaSombria,
	ArmaduraDePlacas,
	EscudoDeMadeira,
	EspadaLonga,
	Machado,
	SimboloDaSerpente,
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
	Item(NomesItens nome, TiposDeItens tipo, bool itemMagico, bool combate, int FA, int dano);
	Item(string nome);

	NomesItens getNome();
	TiposDeItens getTipo();
	bool getItemMagico();
	bool getCombate();
	int getFA();
	int getDano();

	void setNome(NomesItens nome);
	void setTipo(TiposDeItens tipo);
	void setCombate(bool combate);
	void setFA(int FA);
	void setDano(int dano);


	bool bCombate(TiposDeItens tipoItem);

	void montaItem(NomesItens nomeDeItem);

	string getArquivoItens(NomesItens nome);
	string getStringNomesItem(NomesItens nome);
	NomesItens getNomesItem(string nome);
	TiposDeItens getTipoDeItens(string sTipo);
	string getTipoDeItensSignificado(TiposDeItens tipo);

private:
	NomesItens nome;
	TiposDeItens tipo;
	bool itemMagico;
	bool combate;
	int FA;
	int dano;
};