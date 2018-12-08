#include <vector>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;
    
    string intString = to_string(n);
    int Size = intString.size();
    const char* stringOneChar = intString.c_str();
    
    for(int i = 0; i < Size; i++){
        answer += (stringOneChar[i] - '0');
    }
    return answer;
}