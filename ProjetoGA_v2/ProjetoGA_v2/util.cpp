#include "util.h"
#include <locale>
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
/*Item monta_item(NomesItens nomeItem) {
	if (nomeItem == NomeIndefinido) {
		Item itemMontado(NomeIndefinido, TipoIndefinido, false, 0, 0);
		return itemMontado; // Retorna ponteiro nulo se a string estiver vazia
	}
	string arquivoDoItem = getArquivoItens(nomeItem);
	string conteudoArquivoItem = acessaArquivo(arquivoDoItem);
	vector<string> partesItem = split(conteudoArquivoItem, ';');
	NomesItens itemNome = nomeItem;
	TiposDeItens itemTipo = getTipoDeItens(nomeItem);
	bool itemCombate = string_to_bool(partesItem[0]);
	int itemFA = stoi(partesItem[1]);
	int itemDano = stoi(partesItem[2]);
	Item itemMontado(itemNome, itemTipo, itemCombate, itemFA, itemDano);
	return itemMontado;
}*/

void pressiona_prosseguir() {
	cout << "\n" << "Pressione ENTER para prosseguir...";
	cin.ignore();
	cin.get();
}

string pressiona_escolha() {
	setlocale(LC_ALL, "pt_BR.UTF-8");
	string escolha = "";
	cout << "\n" << u8"Digite o número da opção desejada:   "; //u8 para exbir os acentos
	cin >> escolha;
	return escolha;
}

void limpar_tela() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void removeQuebrasDeLinhaExtremidades(std::string& texto) {
	// Remove '\n' do começo
	while (!texto.empty() && texto.front() == '\n') {
		texto.erase(0, 1);
	}

	// Remove '\n' do final
	while (!texto.empty() && texto.back() == '\n') {
		texto.pop_back();
	}
}

