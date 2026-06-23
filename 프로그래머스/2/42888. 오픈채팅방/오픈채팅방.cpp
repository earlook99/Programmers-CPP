#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> mp;
    vector<pair<string, string*>> v;
    
    for (auto& r : record)
    {
        stringstream ss(r);
        string behav, uid, nick;
        ss >> behav >> uid >> nick;
        
        switch (behav[0])
        {
            case 'E':
                mp[uid] = nick;
                v.push_back({behav, &mp[uid]});
                break;
            case 'L':
                v.push_back({behav, &mp[uid]});
                break;
            case 'C':
                mp[uid] = nick;
                break;
            default:
                break;
        }
    }
    
    for (auto& p : v)
    {
        if (p.first == "Enter") answer.push_back(*p.second + "님이 들어왔습니다.");
        else answer.push_back(*p.second + "님이 나갔습니다.");
    }
    
    return answer;
}