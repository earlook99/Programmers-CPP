#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0;
    int zerocnt = 0;
    
    for (auto l : lottos)
    {
        if (l == 0) zerocnt++;
        
        auto it = find(win_nums.begin(), win_nums.end(), l);
        if (it != win_nums.end())
        {
            cnt++;
        }
    }
    
    answer.push_back(min(7 - (cnt + zerocnt), 6));
    answer.push_back(min(7 - cnt, 6));
    
    return answer;
}