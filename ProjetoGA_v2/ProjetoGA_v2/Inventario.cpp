#include "Inventario.h"

Inventario::Inventario() {
    provisao = 0;
    tesouro = 0;
}
Inventario::Inventario(vector<Item*> itens, int provisao, int tesouro) {

}

vector<Item*> Inventario::getItens() {
    return itens;
}
int Inventario::getProvisao() {
    return provisao;
}
int Inventario::getTesouro() {
    return tesouro;
}

void Inventario::setProvisao(int novaProvisao) {
    provisao = novaProvisao;
}
void Inventario::setTesouro(int novoTesouro) {
    tesouro = novoTesouro;
}

void Inventario::addItem(Item* item) {
    itens.push_back(item);
}
void Inventario::rmItem(Item* item) {
    auto it = find(itens.begin(), itens.end(), item);
    if (it != itens.end()) {
        itens.erase(it);
    }
}
void Inventario::addProvisao(int quantidade) {
    provisao += quantidade;
}
void Inventario::rmProvisao(int quantidade) {
    provisao -= quantidade;
    if (provisao < 0) {
        provisao = 0;
    }
}
void Inventario::addTesouro(int valor) {
    tesouro += valor;
}
void Inventario::rmTesouro(int valor) {
    tesouro -= valor;
    if (tesouro < 0) {
        tesouro = 0;
    }
}