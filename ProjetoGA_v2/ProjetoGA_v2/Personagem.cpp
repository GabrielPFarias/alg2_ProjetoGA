#include "Personagem.h"

Personagem::Personagem(string nome, int habilidade, int energia, int sorte) {
    this->nome = nome;
    this->habilidade = habilidade;
    this->energia = energia;
    this->sorte = sorte;
}
string Personagem::getNome() {
    return nome;
}
int Personagem::getHabilidade() {
    return habilidade;
}
int Personagem::getEnergia() {
    return energia;
}
int Personagem::getSorte() {
    return sorte;
}
void Personagem::setNome(string novoNome) {
    nome = novoNome;
}
void Personagem::setHabilidade(int novaHabilidade) {
    habilidade = novaHabilidade;
}
void Personagem::setEnergia(int novaEnergia) {
    energia = novaEnergia;
}
void Personagem::setSorte(int novaSorte) {
    sorte = novaSorte;
}
