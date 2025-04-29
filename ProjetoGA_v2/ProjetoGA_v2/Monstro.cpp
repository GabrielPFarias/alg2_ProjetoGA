#pragma once
#include "Monstro.h"

Monstro::Monstro() {
	nome = MonstroIndefinido;
	montaMonstro(nome);
}

Monstro::Monstro(NomesMonstros nome) {
	montaMonstro(nome);
}

Monstro::Monstro(NomesMonstros nome, int habilidade, int energia, int sorte, int provisao, int tesouro)
	: nome(nome), Personagem(habilidade, energia, sorte), provisao(provisao), tesouro(tesouro) {}

void Monstro::montaMonstro(NomesMonstros nomeMonstro) {
	if (nomeMonstro == MonstroIndefinido) {
		nome = MonstroIndefinido;
		habilidade = 0;
		energia = 0;
		sorte = 0;
		pItem = nullptr;
	}
	else {
		string nomeArquivo = getArquivoMonstro(nomeMonstro);
		string conteudo = acessaArquivo(nomeArquivo);
		vector<string> partesConteudo = split(conteudo, '#');
		for (int i = 0; i < partesConteudo.size(); i++) {
			removeQuebrasDeLinhaExtremidades(partesConteudo[i]);
		}
		nome = nomeMonstro;
		habilidade = stoi(partesConteudo[0]);
		energia = stoi(partesConteudo[1]);
		sorte = stoi(partesConteudo[2]);
		tesouro = stoi(partesConteudo[3]);
		provisao = stoi(partesConteudo[4]);
		string sItem = partesConteudo[5];

		pItem = new Item(pItem->getNomesItem(sItem));
	}
	
}

string Monstro::getStringMonstro(NomesMonstros nome) {
	switch (nome) {
		case Dragao: return "Dragão";
		case NomeIndefinido: return "";
	}
}

NomesMonstros Monstro::getNomeMonstro(string strNome) {
	if (strNome == "Dragao" || strNome == "dragao" || strNome == "Dragão" || strNome == "dragão") return Dragao;
	else if (strNome == "") return MonstroIndefinido;
	else return MonstroIndefinido;
	
}

string Monstro::getArquivoMonstro(NomesMonstros nome) {
	switch (nome) {
		case Dragao: return "arquivos/monstros/dragao.txt";
		case NomeIndefinido: return "";
	}
}