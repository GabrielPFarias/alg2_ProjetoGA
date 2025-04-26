#include "util.h"
#include <fstream>
#include <sstream>

string acessaArquivo(string nomeArquivo) {
	ifstream arquivo(nomeArquivo);
	stringstream buffer;
	buffer << arquivo.rdbuf();
	string conteudo = buffer.str();
	return conteudo;
}
vector<string> split(string str, char delimitador) {
	vector<string> partes;
	stringstream ss(str);
	string parte;

	while (getline(ss, parte, delimitador)) {
		partes.push_back(parte);
	}

	return partes;
}
bool verificar_valor(const string& sItem, int index) {
	vector<string> partes = split(sItem, ';');
	if (index < partes.size()) {
		return partes[index] == "1";
	}
	return false; 
}
bool string_to_bool(string str) {
	if (str == "0") {
		return false;
	}
	else if (str == "1") {
		return true;
	}
}

