#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

string acessaArquivo(string nomeArquivo);
vector<string> split(string str, char delimitador);
bool verificar_valor(const string& sItem, int index);
bool string_to_bool(string str);
Item* monta_item(string sItem);
void pressiona_prosseguir();
string pressiona_escolha();