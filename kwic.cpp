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
		void readInput();

};

Kwic::Kwic() {

}

void Kwic::setOrder(int id) {
	if (id == 1) {
		this->orderStrategy = new Alphabetic();
	} else {
		this->orderStrategy = nullptr;
	}
}

void Kwic::setProcess(int id) {
	if (id == 1) {
		this->processStrategy = new Permutation();
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

void Kwic::readInput() {
	int n = 0;
	cout << "Cuantos enunciados: ";
	cin >> n;
	cin >> ws;
	for (int i = 0; i < n; i++) {
		string sentence = "";
		getline(std::cin, sentence);
		this->list.push_back(sentence);
	}
	cout << endl;
}