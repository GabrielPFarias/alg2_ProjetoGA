#include "Item.h"

Item::Item(NomesItens nomeItem) {
    montaItem(nomeItem);
}
Item::Item() {
    NomesItens nomeItem = NomeIndefinido;
    montaItem(nomeItem);
}
Item::Item(string nome) {
    NomesItens nomeItem = getNomesItem(nome);
    montaItem(nomeItem);
}
Item::Item(NomesItens nome, TiposDeItens tipo, bool itemMagico, bool combate, int FA, int dano) {
    this->nome = nome;
    this->tipo = tipo;
    this->itemMagico = itemMagico;
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
bool Item::getItemMagico() {
    return itemMagico;
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
        itemMagico = false;
        combate = false;
        dano = 0;
        FA = 0;
    }
    else {
        string arquivoDoItem = getArquivoItens(nomeDoItem);
        string conteudoArquivoItem = acessaArquivo(arquivoDoItem);
        vector<string> partesItem = split(conteudoArquivoItem, ';');
        nome = nomeDoItem;
        tipo = getTipoDeItens(partesItem[0]);
        itemMagico = string_to_bool(partesItem[1]);
        combate = bCombate(tipo);
        FA = stoi(partesItem[2]);
        dano = stoi(partesItem[3]);
    }
}

bool Item::bCombate(TiposDeItens tipoItem) {
    if (tipoItem == W){
        return true;
    }
    else {
        return false;
    }
}
string Item::getArquivoItens(NomesItens nome) {
    switch (nome) {
    case Porrete:               return "arquivos/itens/porrete.txt";
    case LivroDeFeiticos:       return "arquivos/itens/livro_de_feiticos.txt";
    case Feitico:               return "arquivos/itens/feitico.txt";
    case Chave:                 return "arquivos/itens/chave.txt";
    case Amuleto:               return "arquivos/itens/amuleto.txt";
    case AdagaSombria:          return "arquivos/itens/adaga_sombria.txt";
    case ArmaduraDePlacas:      return "arquivos/itens/armadura_de_placas.txt";
    case EscudoDeMadeira:       return "arquivos/itens/escudo_de_madeira.txt";
    case EspadaLonga:           return "arquivos/itens/espada_longa.txt";
    case Machado:               return "arquivos/itens/machado.txt";
    case SimboloDaSerpente:     return "arquivos/itens/simbolo_da_serpente.txt";
    case NomeIndefinido:        return "";
    default:                    return "Desconhecido";
    }
}
string Item::getStringNomesItem(NomesItens nome) {
    switch (nome) {
    case Porrete:               return "Porrete";
    case LivroDeFeiticos:       return u8"Livro de Feitiços";
    case Feitico:               return u8"Feitiço";
    case Chave:                 return "Chave";
    case Amuleto:               return "Amuleto";
    case AdagaSombria:          return "Adaga Sombria";
    case ArmaduraDePlacas:      return "Armadura de Placas";
    case EscudoDeMadeira:       return "Escudo de Madeira";
    case EspadaLonga:           return "Espada Longa";
    case Machado:               return "Machado";
    case SimboloDaSerpente:     return u8"Símbolo da Serpente";
    case NomeIndefinido:        return "";
    default:                    return "Desconhecido";
    }
}
NomesItens Item::getNomesItem(string nome) {
    transform(nome.begin(), nome.end(), nome.begin(), ::tolower);

    if (nome == "porrete") return Porrete;
    if (nome == "livro de feiticos" || nome == "livro de feitiços") return LivroDeFeiticos;
    if (nome == "feitico" || nome == "feitiço") return Feitico;
    if (nome == "chave") return Chave;
    if (nome == "amuleto") return Amuleto;
    if (nome == "adaga_sombria") return AdagaSombria;
    if (nome == "armadura de placas") return ArmaduraDePlacas;
    if (nome == "escudo de madeira") return EscudoDeMadeira;
    if (nome == "espada longa") return EspadaLonga;
    if (nome == "machado") return Machado;
    if (nome == "simbolo da serpente" || nome == "símbolo da serpente") return SimboloDaSerpente;
    return NomeIndefinido;
}
TiposDeItens Item::getTipoDeItens(string sTipo){
    if (sTipo == "c" || sTipo == "C") return C;
    if (sTipo == "w" || sTipo == "W") return W;
    if (sTipo == "r" || sTipo == "R") return R;
    else return TipoIndefinido;
}

string Item::getTipoDeItensSignificado(TiposDeItens tipo) {
    switch (tipo) {
    case W:         return "Arma";
    case C:         return "Comum";
    case R:         return "Armadura";
    default:              return "";
    }
}