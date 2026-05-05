#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int start;
    int multiplier = 1;
    int len;
    
    len = s.length();
    
    if (s[0] == '+' || s[0] == '-')
    {
        if (s[0] == '-')
            multiplier = -1;
        start = 1;
    }
    else
        start = 0;
    
    for (int i = start; i < len; i++)
    {
        answer *= 10;
        answer += s[i] - 48;
    }
    
    answer *= multiplier;
    
    return answer;
}