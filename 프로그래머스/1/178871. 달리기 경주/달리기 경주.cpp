#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> mp;
    
    for (int i = 0; i < players.size(); i++)
    {
        mp[players[i]] = i;
    }
    
    for (const string& c : callings)
    {
        int idx = mp[c];
        string& front = players[idx - 1];

        mp[c] = idx - 1;
        mp[front] = idx;

        swap(players[idx - 1], players[idx]);
    }
    
    answer = players;
    
    return answer;
}