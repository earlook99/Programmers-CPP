#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char, int> mp_x;
    map<char, int> mp_y;
    
    for (const auto& x : X)
    {
        mp_x[x]++;
    }
    for (const auto& y : Y)
    {
        mp_y[y]++;
    }
    
    for (char i = '9'; i >= '0'; i--)
    {
        for (int j = 0; j < min(mp_x[i], mp_y[i]); j++)
        {
            answer += i;
        }
    }
    
    if (answer == "") answer = "-1";
    if (all_of(answer.begin(), answer.end(), [](char c) { return c == '0'; })) answer = "0";
    
    return answer;
}