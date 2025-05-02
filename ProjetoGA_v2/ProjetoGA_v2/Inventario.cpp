#include "Inventario.h"
#include <locale>

Inventario::Inventario() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    provisao = 0;
    tesouro = 0;
}
Inventario::Inventario(vector<Item*> itens, int provisao, int tesouro) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    this->itens = itens;
    this->provisao = provisao;
    this->tesouro = tesouro;
}
Inventario::~Inventario() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    // Percorra o vetor e delete cada item dinamicamente alocado
    for (auto item : itens) {
        delete item;  // Libera a memória alocada para cada item
    }
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
        delete* it;
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
void Inventario::imprimir() {
    cout << "Inventário:" << endl;
    cout << "Provisão: " << provisao << endl;
    cout << "Tesouro: " << tesouro << endl;

    cout << "\nItens: " << endl;
    if (itens.empty()) {
        cout << "Nenhum item no inventário." << endl;
    }
    else {
        for (size_t i = 0; i < itens.size(); ++i) {
            cout << "Item " << i + 1 << ":" << endl;
            cout << "  Nome: " << itens[i]->getNome() << endl;
            cout << "  Tipo: " << itens[i]->getTipo() << endl;
            cout << "  FA: " << itens[i]->getFA() << endl;
            cout << "  Dano: " << itens[i]->getDano() << endl;
            cout << "  Combate: " << (itens[i]->getCombate() ? "Sim" : "Não") << endl;
            cout << endl;
        }
    }
}
void Inventario::imprimirResumido() {
    vector<string> sItens;
    int i = 0;
    for (i = 0;i < itens.size(); i++) {
        NomesItens nomeItem = itens[i]->getNome();
        string sItem = itens[i]->getStringNomesItem(nomeItem);
        sItens.push_back(sItem);
    }
    cout << u8"Esses são os itens disponiveis:\n\n" << endl;
    for (i = 0;i < sItens.size(); i++) {
        cout << "(" << i + 1 << ") " << sItens[i] << "    ";
    }
    cout << "(" << i + 1 << ") " << "Cancelar" << "    \n";
}
string Inventario::getTodosDados(){
    string conteudo;
    int i;
    conteudo = to_string(provisao);
    conteudo = conteudo + "." + to_string(tesouro) + ".";

    for (size_t i = 0; i < itens.size(); i++) {
        if (i > 0) {
            conteudo += ",";
        }
        conteudo += itens[i]->getStringNomesItem(itens[i]->getNome());
    }
    return conteudo;
}

bool Inventario::temItem(NomesItens nomeItem) {
    for (int i = 0; i < itens.size(); i++) {
        if (nomeItem == itens[i]->getNome()) {
            return true;
        }
    }
    return false;
}