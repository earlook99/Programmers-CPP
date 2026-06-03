#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 1234;
    vector<vector<int>> dp = board;
    
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (i-1 < 0 || j-1 < 0) continue;
            if (dp[i][j] == 1) dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
        }
    }
    
    int max_val = dp[0][0];
    for (const auto& r : dp)
    {
        int row_max = *max_element(r.begin(), r.end());
        max_val = max(row_max, max_val);
    }
    
    answer = max_val * max_val;
    
    return answer;
}