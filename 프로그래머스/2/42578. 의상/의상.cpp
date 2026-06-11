#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> mp;
    
    for (auto& c : clothes)
    {
        mp[c[1]]++;
    }
    
    for (auto& m : mp)
    {
        answer *= (m.second + 1);
    }
    
    answer--;
    
    return answer;
}