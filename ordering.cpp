#include <algorithm>

using namespace std;

class Ordering {
	public:
		Ordering() {};
		virtual vector<string> order(vector<string> list) = 0;
};

class Alphabetic : public Ordering {
	public:
		Alphabetic() {};
		vector<string> order(vector<string> list);
};

vector<string> Alphabetic::order(vector<string> list) {
	sort(list.begin(), list.end());
	return list;
}