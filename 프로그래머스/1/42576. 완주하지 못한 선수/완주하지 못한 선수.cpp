#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> cnt;
    
    for (int i = 0; i < participant.size(); i++)
    {
        cnt[participant[i]]++;
        
        if (i == completion.size()) break;
        
        cnt[completion[i]]--;
    }
    
    for (auto& p : cnt)
    {
        if (p.second != 0)
        {
            answer = p.first;
            break;
        }
    }
    
    return answer;
}