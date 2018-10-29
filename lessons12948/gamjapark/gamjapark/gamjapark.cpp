#include <string>
#include <vector>
using namespace std;

string solution(string phone_number) {
	int Size = phone_number.size();
	char * stringOneText = new char[Size + 1];
	strcpy(stringOneText, phone_number.c_str());
	for (int i = Size - 5; i >= 0; i--)
		stringOneText[i] = '*';
	string answer(stringOneText);
	return answer;
}