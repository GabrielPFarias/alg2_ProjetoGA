#pragma once
#include <string>
#include <vector>

using namespace std;

string acessaArquivo(string nomeArquivo);
vector<string> split(string str, char delimitador);
bool verificar_valor(const string& sItem, int index);
bool string_to_bool(string str);