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
	if (partesConteudo.size() < 6) { // caso o arquivo nao tenha 6 partes
		partesConteudo.resize(6, ""); // formata o vetor em 6 partes
	}
	for (int i = 0; i < partesConteudo.size(); i++) {
		removeQuebrasDeLinhaExtremidades(partesConteudo[i]);
	}
	string sHeader = partesConteudo[0];
	string sTexto = partesConteudo[1];
	string sItem = partesConteudo[2];
	string sTextosEscolhas = partesConteudo[3];
	string sArquivosEscolhas = partesConteudo[4];
	string sMonstro = partesConteudo[5];
	
	bItem = verificar_valor(sHeader, 0); // Verifica se tem item na cena
	bBatalha = verificar_valor(sHeader, 1); // Verifica se tem batalha na cena

	texto = sTexto;
	if (temItem()) {
		pItem = new Item(NomeIndefinido);
		pItem->montaItem(pItem->getNomesItem(sItem));
	}

	vector<string> parteTextosEscolhas = split(sTextosEscolhas, ';');
	if (parteTextosEscolhas.size() < 2) {
		parteTextosEscolhas.resize(2, "");
	}
	textosEscolhas = parteTextosEscolhas;

	vector<string> parteArquivosEscolhas = split(sArquivosEscolhas, ';');
	if (parteArquivosEscolhas.size() < 2) {
		parteArquivosEscolhas.resize(2, "");
	}
	arquivosEscolhas = parteArquivosEscolhas;
	if (temBatalha()) {
		pMonstro = new Monstro(MonstroIndefinido);
		pMonstro->montaMonstro(pMonstro->getNomeMonstro(sMonstro));
	}
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
	if (nomeArquivo == "arquivos/cenas/gameover.txt" || nomeArquivo == "arquivos/cenas/victory_royale.txt") {
		bFim = true;
	}
	else {
		bFim = false;
	}
}
string Cena::getTexto() {
	return texto;
}
string Cena::getArqMonstro() {
	return arqMonstro;
}
Monstro* Cena::getMonstro() {
	return pMonstro;
}
vector<string> Cena::getTextosEscolhas() {
	return textosEscolhas;
}
vector<string> Cena::getArquivosEscolhas() {
	return arquivosEscolhas;
}
Item* Cena::getItem() {
	return pItem;
}
bool Cena::temFim() {
	return bFim;
}
void Cena::getProximaCena(string escolha) {
	while (escolha != "1" && escolha != "2" && escolha != "e") {
		cout << u8"\nValor inválido. Envie outro." << endl;
		escolha = pressiona_escolha();
	}
	setArquivoCena(arquivosEscolhas[stoi(escolha)-1]);
}
string Cena::getNomeArquivo() {
	return nomeArquivo;
}






