#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for (char c : new_id) answer += tolower(c);
    
    string tmpstr = "";
    for (char c : answer)
    {
        if (islower(c) || isdigit(c) || c == '-' || c == '_' || c == '.')
        {
            tmpstr += c;
        }
    }
    answer = tmpstr;
    
    tmpstr = "";
    char prev = 0;
    for (char c : answer)
    {
        if (c == '.' && prev == '.') continue;
        tmpstr += c;
        prev = c;
    }
    answer = tmpstr;
    
    if (answer.front() == '.') answer.erase(0, 1);
    if (answer.back() == '.') answer.pop_back();
    
    if (answer.empty()) answer += 'a';
    
    if (answer.length() >= 16) answer.resize(15);
    if (answer.back() == '.') answer.pop_back();
    
    while (answer.length() <= 2)
    {
        answer += answer.back();
    }
    
    return answer;
}