#include <vector>
#include <string>
#include <fstream>

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
    vector<string> readStopWords();
    vector<string> getWords(const string& sentence);
};

vector<string> StopWords::readStopWords() {
  cout << "Como se llama tu archivo de stop words?" << endl;
  string file_name;
  cin >> file_name;
  ifstream file(file_name);
  vector<string> lines;
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			lines.push_back(line);
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
  vector<string> stop_words = this->readStopWords();
  vector<string> new_list;
  for (int i = 0; i < list.size(); ++i) {
    vector<string> item = this->getWords(list[i]);
    string new_sentence = "";
    for (const string& word : item) {
      bool insert = true;
      for (const string& stop_word : stop_words) {
        if (word == stop_word) {
          insert = false;
        }
      }
      if (insert) {
        new_sentence += word + " ";
      }
    }
    new_sentence.pop_back();
    new_list.push_back(new_sentence);
  }
  return new_list;
}
