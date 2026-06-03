#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int st = 0;
    
    for (const auto& c : s)
    {
        if (c == '(') st++;
        else st--;
        
        if (st < 0) return false;
    }
    
    if (st != 0) return false;

    return answer;
}