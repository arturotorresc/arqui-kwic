#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "kwic.cpp"

using namespace std;

int main () {
	int option = 0;
	Kwic *kwic = nullptr;
	cout << "Quieres leer desde la consola o desde un archivo ?" << endl;
	cout << "(1, consola), (2, archivo)";
	cin >> option;

	switch (option) {
		case 1: {
			kwic = new KwicConsole();
			break;
		}
		case 2: {
			string file_name;
			cout << "Cómo se llama el archivo?" << endl;
			cin >> file_name;
			kwic = new KwicReadFile(file_name);
			break;
		}
		default:
			cout << "Opción no valida" << endl;
	}

	cout << "Estrategia de Preprocesamiento: (1, StopWords), (2, nada)" << endl;
	cin >> option;
	kwic->setPreprocess(option);
	cout << "Estrategia de procesamiento: (1, kwic indexing) (2, Imprime lineas y Opcion de eliminar)" << endl;
	cin >> option;
	kwic->setProcess(option);
	cout << "Estrategia de ordenamiento: (1, alfabético ascendiente) (2, alfabético descendiente)" << endl;
	cin >> option;
	kwic->setOrder(option);
	cout << "Tipo de representamiento: (1, consola, 2, consola imprime lineas y Opcion de eliminar)" << endl;
	cin >> option;
	kwic->setRepresent(option);

	kwic->execute();

	return 0;
}