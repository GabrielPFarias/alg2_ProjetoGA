#include "Tela.h"

Tela::Tela(Cena* cena) {
	this->cena = cena;
}
void Tela::exibir() {
	//system("cls");
	cout << cena->getTexto() << endl;
}
