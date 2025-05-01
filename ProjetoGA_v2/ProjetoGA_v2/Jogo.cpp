#include "Jogo.h"

Jogo::Jogo() {
	setlocale(LC_ALL, "pt_BR.UTF-8"); // Para usar acentos e cedilha no terminal
}
Jogo::Jogo(Jogador* jogador, Cena* cena) {
	this->jogador = jogador;
	this->cena = cena;
	setlocale(LC_ALL, "pt_BR.UTF-8"); // Para usar acentos e cedilha no terminal
}
void Jogo::iniciaJogo() {
	Cena cenaAtual("arquivos/tela_abertura.txt");
	Tela tela(&cenaAtual);
	Jogador jogador;
	bool fimDeJogo = false;

	cenaAtual.montaCena();
	tela.exibirTexto();

	switch (stoi(pressiona_escolha())) {
	case 1:
		jogador.inicializaJogador();
		jogador.imprimirInventario();
		pressiona_prosseguir();
		cenaAtual.setArquivoCena("arquivos/cenas/1.txt");
		break;
	case 2:
		carregarJogo();

		break;
	case 3:
		break;
	case 4:
		break;
	}
	while (fimDeJogo == false) {
		tela.exibirTexto();
		if (fimDeJogo = cenaAtual.temFim()) {
			break;
		}
		else {
			if (cenaAtual.temBatalha()) {
				pressiona_prosseguir();
				limpar_tela();
				Batalha batalha(cenaAtual.getMonstro(), &jogador);
				batalha.iniciaBatalha();
			}
			else {
				tela.exibirEscolhas();
				if (cenaAtual.temItem()) {
					jogador.addItemInventario(cenaAtual.getItem());
				}
				string escolha = pressiona_escolha();
				if (escolha == "e") {
					jogador.imprimirInventario();
					pressiona_prosseguir();
				}
				else if (escolha == "s") {
					salvar();
				}
				else {
					cenaAtual.getEscolhaJogador(escolha);
				}

			}
		}
	}
}
void Jogo::salvar() {
	limpar_tela();
	cout << "Qual nome você deseja dar a esse "
}

carregearJogo{
	cenaAtual = cenaque ta no arquivo;
}