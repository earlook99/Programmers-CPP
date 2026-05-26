#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string newAlpha = "";
    
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (skip.find(i) == string::npos)
        {
            newAlpha += i;
        }
    }
    
    int len = newAlpha.length();
    
    for (const char& c : s)
    {
        int idx = newAlpha.find(c);
        answer += newAlpha[(idx + index) % (len)];
    }
    
    
    return answer;
}