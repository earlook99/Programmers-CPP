#include <vector>
#include <algorithm>

using namespace std;

int M, N;
vector<vector<bool>> visited;
vector<vector<int>> board;

int apeach(int num, int r, int c)
{
    if (r < 0 || c < 0 || r >= M || c >= N) return 0;
    if (visited[r][c]) return 0;
    if (board[r][c] != num) return 0;

    visited[r][c] = true;
    return 1 + apeach(num, r-1, c) + apeach(num, r+1, c) + apeach(num, r, c-1) + apeach(num, r, c+1);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    M = m;
    N = n;
    board = picture;
    visited.assign(m, vector<bool>(n, false));
    
    for (int i = 0; i < picture.size(); i++)
    {
        for (int j = 0; j < picture[0].size(); j++)
        {
            if (picture[i][j] != 0)
            {
                int area = apeach(picture[i][j], i, j);
                if (area >= 1)
                {
                    number_of_area++;
                    max_size_of_one_area = max(max_size_of_one_area, area);
                }
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}