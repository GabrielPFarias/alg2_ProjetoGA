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
Item* monta_item(string sItem) {
	vector<string> partesItem = split(sItem, ';');
	string itemNome = partesItem[0];
	string itemTipo = partesItem[1];
	bool itemCombate = string_to_bool(partesItem[2]);
	int itemFA = stoi(partesItem[3]);
	int itemDano = stoi(partesItem[4]);
	Item itemMontado(itemNome, itemTipo, itemCombate, itemFA, itemDano);
	return &itemMontado;
}

void pressiona_prosseguir() {
	cout << "Pressione ENTER para prosseguir...";
	cin.ignore();
	cin.get();
}

string pressiona_escolha() {
	string escolha = "";
	cout << "Digite o número da opção desejada:";
	cin >> escolha;
	return escolha;
}