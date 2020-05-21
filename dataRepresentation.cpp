#include <vector>
#include <iostream>
#include <string>

using namespace std;

class DataRepresentation {
	public:
		DataRepresentation() {};
		virtual void represent(vector<string> list) = 0;
};

class ShowData : public DataRepresentation {
	public:
		ShowData() {};
		void represent(vector<string> list);
};

void ShowData::represent(vector<string> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << i << ". "<< list[i] << endl;
	}
}

class ShowDataDel : public DataRepresentation {
	public:
		ShowDataDel() {};
		void represent(vector<string> list);
		void eraseLines(vector<string> list);
};

void ShowDataDel::represent(vector<string> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << i << ". "<< list[i] << endl;
	}

	string elim = "";
	cout << "Deseas eliminar lineas de salida? (y/n)" << endl;
	cin >> elim;

	if (elim == "y") {
		this->eraseLines(list);
	}
}

void ShowDataDel::eraseLines(vector<string> list) {
	int i = 0;
	cout << "Cual linea deseas eliminar?" << endl;
	cin >> i;
	list.erase(list.begin()+i, list.begin()+i+1);

	this->represent(list);
}