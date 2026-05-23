#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int dateToInt(string date)
{
    int result = 0;
    
    result += stoi(date.substr(0, 4)) * 336;
    result += stoi(date.substr(5, 2)) * 28;
    result += stoi(date.substr(8, 2));
    
    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> mp;
    int td = dateToInt(today);
    
    for (const string& t : terms)
    {
        mp[t[0]] = stoi(t.substr(2));
    }
    
    for (int i = 0; i < privacies.size(); i++)
    {
        int pr = dateToInt(privacies[i].substr(0, 10));
        if (td - pr >= mp[privacies[i][11]] * 28) answer.push_back(i+1);
    }
    
    return answer;
}

