#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<vector<int>> newboard;
    vector<int> baguni;
    
    for (int i = 0; i < board.size(); i++)
    {
        vector<int> newrow;
        
        for (int j = board.size() - 1; j >= 0; j--)
        {
            if (board[j][i] == 0) break;
            newrow.push_back(board[j][i]);
        }
        
        newboard.push_back(newrow);
    }
    
    for (auto& m : moves)
    {
        if (newboard[m-1].empty()) continue;
        
        baguni.push_back(newboard[m-1].back());
        newboard[m-1].pop_back();
        
        if (baguni.size() <= 1) continue;
        
        if (*(baguni.end()-1) == *(baguni.end()-2))
        {
            baguni.erase(baguni.end()-2, baguni.end());
            answer += 2;
        }
    }
    
    return answer;
}