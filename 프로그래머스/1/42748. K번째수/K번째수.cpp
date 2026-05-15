#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto& c : commands)
    {
        vector<int> sub(array.begin() + (c[0]-1), array.begin() + c[1]);
        sort(sub.begin(), sub.end());
        answer.push_back(sub[c[2]-1]);
    }
    
    return answer;
}