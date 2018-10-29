#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	int Min = arr[0];
	int MinNum;

	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] < Min) {
			Min = arr[i];
			MinNum = i;
		}
	}
	vector<int>::iterator iter = arr.begin() + MinNum;
	arr.erase(iter);
	if (arr.size() == 0) arr.push_back(-1);
	return arr;
}