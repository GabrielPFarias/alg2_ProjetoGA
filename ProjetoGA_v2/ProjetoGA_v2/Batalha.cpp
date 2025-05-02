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

    while (1) {
        cout << "Escolha o que deseja fazer na batalha\n\n(1) Atacar\n(2) Usar item\n(3) Fugir" << endl;
        string escolha = pressiona_escolha();
        if (escolha == "1") {
            multiplicador = 2;
            turno();
        }
        else if (escolha == "2") {
            bool itemValido = false;
            while (itemValido == false) {
                limpar_tela();
                jogador->imprimirInventarioResumido();
                string escolha = pressiona_escolha();
                if (stoi(escolha) == jogador->getInventario()->getItens().size() + 1) {
                    limpar_tela();
                    break;
                }
                else {
                    while (1) {
                        Item* itemEscolhido = jogador->getInventario()->getItens()[stoi(escolha) - 1];
                        if (itemEscolhido->getCombate()) {
                            if (itemEscolhido->getItemMagico()) {
                                if (jogador->getMagiaLiberada()) {
                                    usarItem(itemEscolhido);
                                    itemValido = true;
                                    break;
                                }
                                else {
                                    cout << "Para utilizar o Feitiço, você deve possuir o Livro de Feitiços ou ser um MAGO" << endl;
                                    pressiona_prosseguir();
                                    break;
                                }
                            }
                            else {
                                usarItem(itemEscolhido);
                                itemValido = true;
                                break;
                            }
                        }
                        else {
                            cout << "\nO item deve ser do tipo Arma (W) para ser utilizado. Escolha outro item." << endl;
                            pressiona_prosseguir();
                            break;
                        }
                    }
                }
            }
        }
        else if (escolha == "3") {
            break;
        }

        if (jogador->getEnergia() <= 0) {
            resultado = false;
            break;
        }
        else if (monstro->getEnergia() <= 0) {
            resultado = true;
            break;
        } 
    }
}

void Batalha::turno() {
    double faPersonagem = jogador->getHabilidade() + geraValorAleatorio(1, 10);
    double faMonstro = monstro->getHabilidade() + geraValorAleatorio(1, 10);

    if (faPersonagem > faMonstro) {
        geraMultiplicador();
        //perguntaUsarInventario();

        monstro->setEnergia(monstro->getEnergia() - multiplicador);
        cout << "Voce ganhou o turno!\nEnergia monstro: " << monstro->getEnergia() << endl;
    }
    else if (faMonstro > faPersonagem) {
        jogador->rmEnergia(2);
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

bool Batalha::getResultado() {
    return resultado;
}

void Batalha::usarItem(Item* pItem) {
    int danoItem = pItem->getDano();
    monstro->rmEnergia(danoItem);
    jogador->rmItemInventario(pItem);
}