#pragma once
#include<string>
#include <locale>
#include <fstream>
#include "Jogador.h"
#include "cena.h"
#include "Tela.h"
#include "Batalha.h"
#include <filesystem>

using namespace std;

class Jogo
{
public:
	Jogo();
	Jogo(Jogador* jogador, Cena* cenaAtual);
	void iniciaJogo();
	void salvar();
	void carregar();
	void montaJogo(string conteudo);
	string selecionaSave();
	vector<string> getListaJogosSalvos();
	bool verificaArquivosExistentes(string nomeArquivo);
	void recebeItens();
private:
	Jogador* jogador;
	Cena* cenaAtual;
	Batalha* batalha;
	bool end;
};

