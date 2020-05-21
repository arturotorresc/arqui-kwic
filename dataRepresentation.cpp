#include <vector>
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
		cout << list[i] << endl;
	}
}

