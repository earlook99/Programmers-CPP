#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int pos[12];
int answer = 0;

bool is_safe(int row, int col)
{
    for (int i = 0; i < row; i++) 
    {
        if (pos[i] == col || abs(row-i) == abs(col-pos[i]))
            return false;
    }
    return true;
}

void solve(int row, int n)
{
    if (row == n)
    {
        answer++;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (is_safe(row, col))
        {
            pos[row] = col;
            solve(row+1, n);
        }
    }
}

int solution(int n) {
    answer = 0;
    
    solve(0, n);
    
    return answer;
}