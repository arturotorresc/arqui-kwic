#include <fstream>
#include "ordering.cpp"
#include "processing.cpp"
#include "dataRepresentation.cpp"

using namespace std;

class Kwic {
	public:
		Kwic();
		void execute();
		void setOrder(int id);
		void setProcess(int id);
		void setRepresent(int id);
	private:
		Ordering *orderStrategy;
		Processing *processStrategy;
		DataRepresentation *representStrategy;
		vector<string> list;
	protected:
		virtual void readInput() = 0;
		void setList(const vector<string>& list) { this->list = list; }
};

Kwic::Kwic() {

}

void Kwic::setOrder(int id) {
	if (id == 1) {
		this->orderStrategy = new Alphabetic();
	} else if (id == 2) {
		this->orderStrategy = new Descending();
	} else {
		this->orderStrategy = nullptr;
	}
}

void Kwic::setProcess(int id) {
	if (id == 1) {
		this->processStrategy = new Permutation();
	} else if (id == 2) {
		this->processStrategy = new PermutationPrintDel();
	} else {
		this->processStrategy = nullptr;
	}
}

void Kwic::setRepresent(int id){
	if (id == 1) {
		this->representStrategy = new ShowData();
	} else if (id == 2) {
		this->representStrategy = new ShowDataDel();
	} else {
		this->representStrategy = nullptr;
	}
}

void Kwic::execute () {
	this->readInput();
	this->list = this->processStrategy->process(this->list);
	this->list = this->orderStrategy->order(this->list);
	this->representStrategy->represent(this->list);
}

class KwicConsole : public Kwic {
	public:
		KwicConsole() {}
	protected:
		void readInput();
};

void KwicConsole::readInput() {
	int n = 0;
	cout << "Cuantos enunciados: ";
	cin >> n;
	cin >> ws;
	vector<string> lines;
	for (int i = 0; i < n; i++) {
		string sentence = "";
		getline(std::cin, sentence);
		lines.push_back(sentence);
	}
	this->setList(lines);
	cout << endl;
}

// Subclase de Kwic para leer archivos en lugar de recibir el input desde
// la consola
class KwicReadFile : public Kwic {
	public:
		KwicReadFile(const string& file_name) {
			this->file_name = file_name;
		}
	
	protected:
		void readInput();
	
	private:
		string file_name;
};

// Lee las lineas de un archivo txt
void KwicReadFile::readInput() {
	ifstream file(this->file_name);
	if (file.is_open()) {
		string line;
		vector<string> lines;
		while (getline(file, line)) {
			lines.push_back(line);
		}
		this->setList(lines);
		file.close();
	}
}
