#include "Batalha.h"
#include <locale>

Batalha::Batalha() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
}
Batalha::Batalha(Monstro* monstro, Jogador* jogador) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
	this->monstro = monstro;
	this->jogador = jogador;
}
void Batalha::iniciaBatalha() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    geraMultiplicador();
    perguntaUsarInventario();
    cout << "tudo certooooooooooooooooooo" << endl;
    pressiona_prosseguir();
}

bool Batalha::bTestarSorte() {
    cout << "Voce deseja testar sua sorte nesse turno?\n\n(1) SIM\n(2) NAO" << endl;
    string escolha = pressiona_escolha();
    if (escolha == "1")
        return true;
    else if (escolha == "2")
        return false;
}
double Batalha::testarSorte() {
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<> dis(0.75, 1.25);

    double numero = dis(gen);
    return numero;
}
void Batalha::geraMultiplicador() {
    double multiplicador = 1;
    if (bTestarSorte()) {
        double valorAleatorio = testarSorte();
        multiplicador = jogador->getHabilidade() * valorAleatorio;
        if (valorAleatorio > 1) {
            cout << u8"\nVocê deu SORTE, sua habilidade foi aumentada em " << fixed << setprecision(2) << valorAleatorio << endl;
        }
        else {
            cout << u8"\nVocê deu AZAR, sua habilidade foi diminuída em " << fixed << setprecision(2) << 1/valorAleatorio << endl;
        }
        pressiona_prosseguir();
    }
    else {
        multiplicador = 1;
    }
}
void Batalha::perguntaUsarInventario() {
    limpar_tela();
    cout << u8"Você deseja utilizar algum item do inventario?" << endl;
    cout << "\n" << "(1) SIM" << endl;
    cout << u8"(2) NÃO" << endl;
    if (pressiona_escolha() == "1") {
        limpar_tela();
        jogador->imprimirInventarioResumido();
    }
}