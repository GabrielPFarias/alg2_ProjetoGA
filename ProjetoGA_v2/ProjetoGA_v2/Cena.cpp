#include "Cena.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Item.h"

Cena::Cena() {
	nomeArquivo = "";
	bItem = false;
	bBatalha = false;
	texto = "";
	arqMonstro = "";
}

Cena::Cena(string nomeArquivo) {
	this->nomeArquivo = nomeArquivo;
	bItem = false;
	bBatalha = false;
	texto = "";
	arqMonstro = "";
}

void Cena::montaCena(){
	string conteudoArquivo = acessaArquivo(nomeArquivo);
	vector<string> partesConteudo = split(conteudoArquivo, '#');
	string sHeader = partesConteudo[0];
	string sTexto = partesConteudo[1];
	string sItem = partesConteudo[2];
	string sEscolhas = partesConteudo[3];
	string sArquivoMonstro = partesConteudo[4];
	
	bItem = verificar_valor(sHeader, 0);
	bBatalha = verificar_valor(sHeader, 1);

	texto = sTexto;
	
	pItem = monta_item(sItem);

	vector<string> parteEscolhas = split(sEscolhas, ';');
	escolhas = parteEscolhas;

	arqMonstro = sArquivoMonstro;
}
bool Cena::temItem() {
	return bItem;
}
bool Cena::temBatalha() {
	return bBatalha;
}
void Cena::setArquivoCena(string nomeArquivo) {
	this->nomeArquivo = nomeArquivo;
	montaCena();
}
string Cena::getTexto() {
	return texto;
}
string Cena::getArqMonstro() {
	return arqMonstro;
}
vector<string> Cena::getEscolhas() {
	return escolhas;
}
Item* Cena::getItem() {
	return pItem;
}







