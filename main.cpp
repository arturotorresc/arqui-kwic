#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "kwic.cpp"

using namespace std;

int main () {
	int ordering = 0;
	int processing = 0;
	int representing = 0;
	Kwic *kwic = new Kwic();

	cout << "Estrategia de procesamiento: (1, kwic indexing)" << endl;
	cin >> processing;
	cout << "Estrategia de ordenamiento: (1, alfabético ascendiente)" << endl;
	cin >> ordering;
	cout << "Tipo de representamiento: (1, consola, 2, consola imprime lineas y Opcion de eliminar)" << endl;
	cin >> representing;

	kwic->setProcess(processing);
	kwic->setOrder(ordering);
	kwic->setRepresent(representing);

	kwic->execute();

	return 0;
}