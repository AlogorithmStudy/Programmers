#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<int> d, int budget);
int main() {

	vector <int> a;
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);

	cout << solution(a, 10) << endl;

	return 0;
}
int solution(vector<int> d, int budget) {

	sort(d.begin(), d.end(), greater<int>());	//내림차순 정렬
	int size = d.size();

	int count = 0;
	for (int i = 0; i < size; i++) {
		int me = d.back();
		if (me <= budget) {
		
			d.pop_back();
			++count;
			budget -= me;
		}
		else break;
	}
	return count;
}