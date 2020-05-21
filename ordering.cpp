#include <algorithm>
#include <vector>
#include <string>

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

class Descending : public Ordering {
	public:
		Descending() {};
		vector<string> order(vector<string> list);
};

vector<string> Descending::order(vector<string> list) {
	sort(list.begin(), list.end());
	reverse(list.begin(), list.end());
	return list;
}