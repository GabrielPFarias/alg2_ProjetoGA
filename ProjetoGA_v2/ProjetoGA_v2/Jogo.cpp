#include "Jogo.h"

Jogo::Jogo() {
}
Jogo::Jogo(Jogador* jogador, Cena* cena) {
	this->jogador = jogador;
	this->cena = cena;
}
void Jogo::iniciaJogo() {
	Cena cena("abertura.txt");
	Tela tela(&cena);
	Jogador jogador;

	cena.montaCena();
	tela.exibir();

	switch (stoi(pressiona_escolha())) {
	case 1:
		jogador.inicializaJogador();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}

	
}
