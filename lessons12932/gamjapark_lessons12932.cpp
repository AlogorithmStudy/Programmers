#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string intString = to_string(n);
    int Size = intString.size();
    const char* stringOneChar = intString.c_str();
    
    for(int i = Size - 1; i >= 0; i--){
        answer.push_back(stringOneChar[i] - '0');
    }
    return answer;
}