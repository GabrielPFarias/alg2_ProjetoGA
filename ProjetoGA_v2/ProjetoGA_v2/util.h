#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

/*enum NomesItens {
	Porrete,
	LivroDeFeiticos,
	Feitico,
	NomeIndefinido
};

enum TiposDeItens {
	C, R, W, TipoIndefinido //tipo é o tipo de item.Pode ser : c para item comum, r para armadura e w para arma
};*/

string acessaArquivo(string nomeArquivo);
vector<string> split(string str, char delimitador);
bool verificar_valor(const string& sItem, int index);
bool string_to_bool(string str);
void pressiona_prosseguir();
string pressiona_escolha();
void limpar_tela();
void removeQuebrasDeLinhaExtremidades(string& texto);
void cria_arquivo(string nomeArquivo);
