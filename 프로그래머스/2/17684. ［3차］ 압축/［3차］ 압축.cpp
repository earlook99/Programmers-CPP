#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> mp;
    int idx = 1;
    
    while (idx <= 26)
    {
        mp[string(1, (char)('A' + idx-1))] = idx;
        idx++;
    }
    
    for (int i = 0; i < msg.length(); i++)
    {
        string s;
        s += msg[i];
        while (mp.count(s) > 0)
        {
            s += msg[++i];
        }
        
        answer.push_back(mp[s.substr(0, s.length()-1)]);
        mp[s] = idx++;
        
        --i;
    }
    
    
    return answer;
}