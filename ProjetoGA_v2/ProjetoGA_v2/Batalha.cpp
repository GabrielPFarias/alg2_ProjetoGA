#include "Batalha.h"
#include <locale>

Batalha::Batalha() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
}
Batalha::Batalha(Monstro* monstro, Jogador* jogador) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
	this->monstro = monstro;
	this->jogador = jogador;
    this->multiplicador = 2;
    this->resultado = 0;
}
void Batalha::iniciaBatalha() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    while (jogador->getEnergia() > 0 && monstro->getEnergia() > 0) {
        cout << "Escolha o que deseja fazer na batalha\n\n(1) ATACAR\n(2) USAR MAGIA\n(3) FUGIR" << endl;
        string escolha = pressiona_escolha();
        if (escolha == "1") {
            turno();
        }
        else if (escolha == "2") {
            //Usar Magia;
        }
        else if (escolha == "3") {
            break;
        }

        if (jogador->getEnergia() <= 0)
            resultado = -1;
        else if (monstro->getEnergia() <= 0)
            resultado = 1;
    }

    return;
}

void Batalha::turno() {
    double faPersonagem = jogador->getHabilidade() + geraValorAleatorio(1, 10);
    double faMonstro = monstro->getHabilidade() + geraValorAleatorio(1, 10);

    if (faPersonagem > faMonstro) {
        geraMultiplicador();
        perguntaUsarInventario();

        monstro->setEnergia(monstro->getEnergia() - multiplicador);
        cout << "Voce ganhou o turno!\nEnergia monstro: " << monstro->getEnergia() << endl;
    }
    else if (faMonstro > faPersonagem) {
        jogador->setEnergia(jogador->getEnergia() - 2);
        cout << "Voce perdeu o turno!\nSua energia: " << jogador->getEnergia() << endl;   
    }
    else {
        cout << "Empatou!" << endl;
    }
    pressiona_prosseguir();
    return;
}

bool Batalha::bTestarSorte() {
    cout << "Voce deseja testar sua sorte nesse turno?\n\n(1) SIM\n(2) NAO" << endl;
    string escolha = pressiona_escolha();
    if (escolha == "1")
        return true;
    else if (escolha == "2")
        return false;
}
double Batalha::geraValorAleatorio(double min, double max){
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<> dis(min, max);

    double numero = dis(gen);
    return numero;
}
void Batalha::geraMultiplicador() {
    if (bTestarSorte()) {
        double valorAleatorio = geraValorAleatorio(0.75, 1.25);
        multiplicador = multiplicador * valorAleatorio;
        if (valorAleatorio > 1) {
            cout << u8"\nVocê deu SORTE, sua habilidade foi aumentada em " << fixed << setprecision(2) << valorAleatorio << endl;
        }
        else {
            cout << u8"\nVocê deu AZAR, sua habilidade foi diminuída em " << fixed << setprecision(2) << 1/valorAleatorio << endl;
        }
        pressiona_prosseguir();
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

int Batalha::get_resultado() {
    return resultado;
}