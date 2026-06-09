#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    
    while (true)
    {
        vector<vector<bool>> v(board.size(), vector<bool>(board[0].length(), false));
        bool isCompleted = true;
        
        // 2x2 검출 및 마킹
        for (int i = 0; i < board.size()-1; i++)
        {
            for (int j = 0; j < board[0].length()-1; j++)
            {
                if (board[i][j] != 'X' && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1])
                {
                    v[i][j] = true;
                    v[i][j+1] = true;
                    v[i+1][j] = true;
                    v[i+1][j+1] = true;
                    isCompleted = false;
                }
            }
        }
        
        if (isCompleted) break;
        
        // 마킹된 곳 X로
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].length(); j++)
            {
                if (v[i][j])
                {
                    board[i][j] = 'X';
                    answer++;
                }
            }
        }
        
        // 마지막 행부터 역순으로 중력 적용
        for (int i = board.size()-1; i >= 0; i--)
        {
            for (int j = 0; j < board[0].length(); j++)
            {
                if (board[i][j] == 'X')
                {
                    int row = i;
                    while (row >= 0 && board[row][j] == 'X') row--;
                    if (row >= 0)
                    {
                        board[i][j] = board[row][j];
                        board[row][j] = 'X';
                    }
                }
            }
        }
    }
    
    
    
    return answer;
}