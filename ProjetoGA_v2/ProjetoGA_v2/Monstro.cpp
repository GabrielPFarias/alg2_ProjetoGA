#pragma once
#include "Monstro.h"

Monstro::Monstro()
	: Personagem("", 0, 0, 0), provisao(0), tesouro(0) {}

Monstro::Monstro(string nome, int habilidade, int energia, int sorte, int provisao, int tesouro)
	: Personagem(nome, habilidade, energia, sorte), provisao(provisao), tesouro(tesouro) {}

void Monstro::montaMonstro(string nomeArquivo) {
	string conteudo = acessaArquivo(nomeArquivo);
	vector<string> partesConteudo = split(conteudo, '#');

	nome = partesConteudo[0];
	habilidade = stoi(partesConteudo[1]);
	habilidade = stoi(partesConteudo[2]);
	habilidade = stoi(partesConteudo[3]);

}