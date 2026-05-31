#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isFirst = true;
    for (const auto& c : s)
    {
        answer += isFirst ? toupper(c) : tolower(c);
        isFirst = (c == ' ');
    }
    
    return answer;
}