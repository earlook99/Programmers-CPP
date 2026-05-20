#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, set<string>> mp;
    map<string, int> rep;
    
    for (auto r : report)
    {
        stringstream ss(r);
        string reporter, reported;
        ss >> reporter >> reported;
        
        if (mp[reporter].count(reported) == 0)
        {
            mp[reporter].insert(reported);
            rep[reported]++;
        }   
    }
    
    answer.resize(id_list.size());
    for (int i = 0; i < id_list.size(); i++)
    {
        string user = id_list[i];
        for (auto m : mp[user])
        {
            if (rep[m] >= k) answer[i]++;
        }
    }
    
    return answer;
}