#include <iostream>
#include "Cena.h"
#include "Tela.h"
#include "Jogo.h"
#include <locale>

int main() {
	std::setlocale(LC_ALL, "pt_BR.UTF-8"); // Para usar acentos e cedilha no terminal
	/*Cena cena("cenas/1.txt");
	cena.montaCena();

	Tela tela(&cena);
	tela.exibir();


	cena.setArquivoCena("cenas/2.txt");
	tela.exibir();*/
	
	Jogo jogo;
	jogo.iniciaJogo();
 }