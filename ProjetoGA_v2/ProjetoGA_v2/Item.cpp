#include "Item.h"

Item::Item() {
    this->nome = "";
    this->tipo = "";
    this->combate = false;
    this->FA = 0;
    this->dano = 0;
}

Item::Item(string nome, string tipo, bool combate, int FA, int dano) {
    this->nome = nome;
    this->tipo = tipo;
    this->combate = combate;
    this->FA = FA;
    this->dano = dano;
}

string Item::getNome() {
    return nome;
}
string Item::getTipo() {
    return tipo;
}
bool Item::getCombate() {
    return combate;
}
int Item::getFA() {
    return FA;
}
int Item::getDano() {
    return dano;
}
void Item::setNome(string nome) {
    this->nome = nome;
}
void Item::setTipo(string tipo) {
    this->tipo = tipo;
}
void Item::setCombate(bool combate) {
    this->combate = combate;
}
void Item::setFA(int FA) {
    this->FA = FA;
}
void Item::setDano(int dano) {
    this->dano = dano;
}
