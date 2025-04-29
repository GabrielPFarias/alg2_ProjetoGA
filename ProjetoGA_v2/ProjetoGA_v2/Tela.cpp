#include "Tela.h"
#include <vector>
#include <algorithm>
using namespace std;

Tela::Tela(Cena* cena) {
	this->cena = cena;
}
void Tela::exibirTexto() {
	limpar_tela();
	cout << cena->getTexto() << endl;
}
void Tela::exibirEscolhas() {
	vector <string> textosEscolhas = cena->getTextosEscolhas();

	cout << "\n" << "(1) " << textosEscolhas[0] << endl;
	cout << "\n" << "(2) " << textosEscolhas[1] << endl;
}
