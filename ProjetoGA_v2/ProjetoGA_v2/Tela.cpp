#include "Tela.h"
#include <vector>
#include <algorithm>
using namespace std;

Tela::Tela(Cena* cena) {
	
	this->cena = cena;
}
void Tela::exibirTexto() {
	setlocale(LC_ALL, "pt_BR.UTF-8");// Para usar acentos e cedilha no terminal
	cout << cena->getNomeArquivo() << "\n" << endl;
	cout << cena->getTexto() << endl;
}
void Tela::exibirEscolhas() {
	setlocale(LC_ALL, "pt_BR.UTF-8");// Para usar acentos e cedilha no terminal
	vector <string> textosEscolhas = cena->getTextosEscolhas();

	cout << "\n" << " - (1) " << textosEscolhas[0] << endl;
	cout << "\n" << " - (2) " << textosEscolhas[1] << endl;
}
