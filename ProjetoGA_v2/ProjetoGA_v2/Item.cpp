#include "Item.h"

Item::Item(NomesItens nomeItem) {
    montaItem(nomeItem);
}
Item::Item() {
    NomesItens nomeItem = NomeIndefinido;
    montaItem(nomeItem);
}
Item::Item(NomesItens nome, TiposDeItens tipo, bool combate, int FA, int dano) {
    this->nome = nome;
    this->tipo = tipo;
    this->combate = combate;
    this->FA = FA;
    this->dano = dano;
}

NomesItens Item::getNome() {
    return nome;
}
TiposDeItens Item::getTipo() {
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
void Item::setNome(NomesItens nome) {
    this->nome = nome;
}
void Item::setTipo(TiposDeItens tipo) {
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
void Item::montaItem(NomesItens nomeDoItem) {
    if (nomeDoItem == NomeIndefinido) {
        nome = NomeIndefinido;
        tipo = TipoIndefinido;
        combate = false;
        dano = 0;
        FA = 0;
    }
    else {
        string arquivoDoItem = getArquivoItens(nomeDoItem);
        string conteudoArquivoItem = acessaArquivo(arquivoDoItem);
        vector<string> partesItem = split(conteudoArquivoItem, ';');
        nome = nomeDoItem;
        tipo = getTipoDeItens(nomeDoItem);
        FA = stoi(partesItem[1]);
        dano = stoi(partesItem[2]);
    }
}

string Item::getArquivoItens(NomesItens nome) {
    switch (nome) {
    case Porrete:         return "arquivos/itens/porrete.txt";
    case LivroDeFeiticos: return "arquivos/itens/livro_de_feiticos.txt";
    case Feitico:         return "arquivos/itens/feitico.txt";
    case Chave:           return "arquivos/itens/chave.txt";
    case NomeIndefinido:  return "";
    default:              return "Desconhecido";
    }
}
string Item::getStringNomesItem(NomesItens nome) {
    switch (nome) {
    case Porrete:         return "Porrete";
    case LivroDeFeiticos: return u8"Livro De Feitiços";
    case Feitico:         return u8"Feitiço";
    case Chave:           return "Chave";
    case NomeIndefinido:  return "";
    default:              return "Desconhecido";
    }
}
NomesItens Item::getNomesItem(string nome) {
    if (nome == "Porrete" || nome == "porrete") return Porrete;
    if (nome == "Livro De Feiticos" || nome == "livro de feiticos" || nome == "LIVRO DE FEITICOS") return LivroDeFeiticos;
    if (nome == "Feitico" || nome == "feitico" || nome == "FEITICO") return Feitico;
    if (nome == "Chave" || nome == "chave" || nome == "CHAVE") return Chave;
    if (nome == "") return NomeIndefinido;
    //return NomeIndefinido;  // Retorna Indefinido se a string não corresponder a nenhum valor
}
TiposDeItens Item::getTipoDeItens(NomesItens nome) {
    switch (nome) {
    case Porrete:         return W;
    case LivroDeFeiticos: return C;
    case Feitico:         return C;
    case Chave:           return C;
    default:              return TipoIndefinido;
    }
}

string Item::getTipoDeItensSignificado(TiposDeItens tipo) {
    switch (tipo) {
    case W:         return "Arma";
    case C:         return "Comum";
    case R:         return "Armadura";
    default:              return "";
    }
}