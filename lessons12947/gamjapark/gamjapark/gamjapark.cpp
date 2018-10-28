#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool solution(int x) {
	bool answer = true;
	string sizeCheck = to_string(x);
	int size = sizeCheck.size();

	char * oneText = new char[size];
	strcpy(oneText, sizeCheck.c_str());

	int Sum = 0;
	for (int i = 0; i < size; i++)
		Sum += oneText[i] - '0';

	if (x % Sum != 0) answer = false;

	return answer;
}