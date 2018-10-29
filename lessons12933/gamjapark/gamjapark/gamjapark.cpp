#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	string CheckString = to_string(n);
	int Size = CheckString.size();
	char * OneText = new char[Size];
	strcpy(OneText, CheckString.c_str());

	vector<int> SortArray;

	for (int i = 0; i < Size; i++) 
		SortArray.push_back((OneText[i] - '0'));
	sort(SortArray.begin(), SortArray.end());

	for (int i = 0; i < Size; i++) {
		OneText[i] = SortArray.back();
		SortArray.pop_back();
	}
	for (int i = Size - 1; i >= 0; i--) 
		answer += OneText[(Size - 1 - i)] * pow(10, i);

	return answer;
}