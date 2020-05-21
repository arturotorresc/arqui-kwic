#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>

using namespace std;

class Preprocessing {
  public:
    Preprocessing() {}
    virtual vector<string> preprocess(const vector<string>& list) = 0;
};

class NullPreprocess : public Preprocessing {
  public:
    NullPreprocess() {}
    vector<string> preprocess(const vector<string>& list) { return list; }
};

class StopWords : public Preprocessing {
  public:
    StopWords() {}
    vector<string> preprocess(const vector<string>& list);
  private:
    unordered_set<string> readStopWords();
    vector<string> getWords(const string& sentence);
};

unordered_set<string> StopWords::readStopWords() {
  cout << "Como se llama tu archivo de stop words?" << endl;
  string file_name;
  cin >> file_name;
  ifstream file(file_name);
  unordered_set<string> lines;
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			lines.insert(line);
		}
		file.close();
	}
  return lines;
}

vector<string> StopWords::getWords(const string& sentence) {
  vector<string> words;
  string word;
  for (char c : sentence) {
    if (c == ' ') {
      words.push_back(word);
      word = "";
      continue;
    }
    word += c;
  }
  words.push_back(word);
  return words;
}

vector<string> StopWords::preprocess(const vector<string>& list) {
  unordered_set<string> stop_words = this->readStopWords();
  vector<string> new_list;
  for (int i = 0; i < list.size(); ++i) {
    vector<string> item = this->getWords(list[i]);
    string new_sentence = "";
    for (const string& word : item) {
      bool insert = !stop_words.count(word);
      if (insert) new_sentence += word + " ";
    }
    new_sentence.pop_back();
    new_list.push_back(new_sentence);
  }
  return new_list;
}
