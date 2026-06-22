#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for (auto& n : numbers)
    {
        v.push_back(to_string(n));
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for (auto& i : v)
    {
        answer += i;
    }
    
    if (answer[0] == '0') answer = "0";
    
    return answer;
}