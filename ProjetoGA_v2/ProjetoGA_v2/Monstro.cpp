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
NomesMonstros Monstro::getNome() {
	return nome;
}
int Monstro::getProvisao() {
	return provisao;
}
int Monstro::getTesouro() {
	return tesouro;
}
Item* Monstro::getItem() {
	return pItem;
}

string Monstro::getStringMonstro(NomesMonstros nome) {
	switch (nome) {
	case Dragao: return u8"Dragão";
	case Aranha: return "Aranha";
	case Esqueleto: return "Esqueleto";
	case Fantasma: return "Fantasma";
	case Lobisomem: return "Lobisomem";
	case MonstroIndefinido: return "";
	default: return "";
	}
}

NomesMonstros Monstro::getNomeMonstro(string strNome) {
	transform(strNome.begin(), strNome.end(), strNome.begin(), ::tolower);

	if (strNome == "dragao" || strNome == "dragão") return Dragao;
	else if (strNome == "aranha") return Aranha;
	else if (strNome == "esqueleto") return Esqueleto;
	else if (strNome == "fantasma") return Fantasma;
	else if (strNome == "lobisomem") return Lobisomem;
	else return MonstroIndefinido;
}

string Monstro::getArquivoMonstro(NomesMonstros nome) {
	switch (nome) {
	case Dragao: return "arquivos/monstros/dragao.txt";
	case Aranha: return "arquivos/monstros/aranha.txt";
	case Esqueleto: return "arquivos/monstros/esqueleto.txt";
	case Fantasma: return "arquivos/monstros/fantasma.txt";
	case Lobisomem: return "arquivos/monstros/lobisomem.txt";
	case MonstroIndefinido: return "";
	default: return "";
	}
}