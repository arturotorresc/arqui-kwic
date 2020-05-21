#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Processing {
	public:
		Processing() {};
		virtual vector<string> process(vector<string> list) = 0;
};

class Permutation : public Processing {
	public:
		Permutation() {};
		vector<string> process(vector<string> list);
	private:
		vector<string> getWords(string sentence);
		void shiftWords(vector<string> list, vector<string> &setOfWords);
};

vector<string> Permutation::process(vector<string> list) {
	vector<string> setOfWords;
	for (int i = 0; i < list.size(); i++) {
		vector<string> listTemp = this->getWords(list[i]);
		this->shiftWords(listTemp, setOfWords);
	}
	return setOfWords;
}

vector<string> Permutation::getWords(string sentence) {
	string word = "";
	vector<string> list; 
  for (auto x : sentence) { 
  	if (x == ' ') {
      list.push_back(word);
      word = "";
    } 
  	else {
			x = tolower(x);
    	word = word + x; 
    } 
  } 
	list.push_back(word); 
	return list; 
}

void Permutation::shiftWords(vector<string> list, vector<string> &setOfWords) {
	for (int i = 0; i < list.size(); i++) {
		string newSentence = "";
		for (int j = 0; j < list.size(); j++) {
			newSentence += list[j] + " ";
		}
		setOfWords.push_back(newSentence);
		string lastWord = list[list.size() - 1];
		list.pop_back();
		list.insert(list.begin(), lastWord);
	}
}

class PermutationPrintDel : public Processing {
	public:
		PermutationPrintDel() {};
		vector<string> process(vector<string> list);
	private:
		vector<string> getWords(string sentence);
		void shiftWords(vector<string> list, vector<string> &setOfWords);
};

vector<string> PermutationPrintDel::process(vector<string> list) {
	string word = "";
	cout << "Escriba las lineas a eliminar (-1 para parar)" << endl;
	while (word != "-1") {
		cin >> ws;
		getline(cin, word);
		for (int i = 0; i < list.size(); i++) {
			if (list[i] == word)
				list.erase(list.begin() + i);
		}
	}

	cout << "Las lineas a ingresar" << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}

	vector<string> setOfWords;
	for (int i = 0; i < list.size(); i++) {
		vector<string> listTemp = this->getWords(list[i]);
		this->shiftWords(listTemp, setOfWords);
	}
	return setOfWords;
}

vector<string> PermutationPrintDel::getWords(string sentence) {
	string word = "";
	vector<string> list; 
  for (auto x : sentence) { 
  	if (x == ' ') {
      list.push_back(word);
      word = "";
    } 
  	else {
    	word = word + x; 
    } 
  } 
	list.push_back(word); 
	return list; 
}

void PermutationPrintDel::shiftWords(vector<string> list, vector<string> &setOfWords) {
	for (int i = 0; i < list.size(); i++) {
		string newSentence = "";
		for (int j = 0; j < list.size(); j++) {
			newSentence += list[j] + " ";
		}
		setOfWords.push_back(newSentence);
		string lastWord = list[list.size() - 1];
		list.pop_back();
		list.insert(list.begin(), lastWord);
	}
}
