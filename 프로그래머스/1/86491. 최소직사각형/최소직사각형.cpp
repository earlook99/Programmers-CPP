#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int max_h = 0;
    int max_v = 0;
    
    for (auto s : sizes)
    {
        if (s[0] > s[1]) swap(s[0], s[1]);
        
        max_h = max(max_h, s[0]);
        max_v = max(max_v, s[1]);
    }
    
    answer = max_h * max_v;
    
    return answer;
}