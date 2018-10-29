#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
	double answer = 0;
	int Size = arr.size();
	for (int i = 0; i < Size; i++)
		answer += arr[i];

	answer /= Size;
	return answer;
}