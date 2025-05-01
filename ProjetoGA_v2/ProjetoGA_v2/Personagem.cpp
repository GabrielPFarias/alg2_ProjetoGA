#include "Personagem.h"

Personagem::Personagem(int habilidade, int energia, int sorte) {
    this->habilidade = habilidade;
    this->energia = energia;
    this->sorte = sorte;
}
Personagem::Personagem() {
    habilidade = 0;
    energia = 0;
    sorte = 0;
}
/*string Personagem::getNome() {
    return nome;
}*/
int Personagem::getHabilidade() {
    return habilidade;
}
double Personagem::getEnergia() {
    return energia;
}
int Personagem::getSorte() {
    return sorte;
}
/*void Personagem::setNome(string novoNome) {
    nome = novoNome;
}*/
void Personagem::setHabilidade(int novaHabilidade) {
    habilidade = novaHabilidade;
}
void Personagem::setEnergia(double novaEnergia) {
    energia = novaEnergia;
}
void Personagem::setSorte(int novaSorte) {
    sorte = novaSorte;
}
