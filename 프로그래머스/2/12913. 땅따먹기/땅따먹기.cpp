#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<int> prev = {0, 0, 0, 0};
    vector<int> cur = {0, 0, 0, 0};
    
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int mx = 0;
            for (int k = 0; k < 4; k++)
            {
                if (k == j) continue;
                
                mx = max(prev[k], mx);
            }
            cur[j] = land[i][j] + mx;
        }
        prev = cur;
    }
    
    answer = max({cur[0], cur[1], cur[2], cur[3]});

    return answer;
}