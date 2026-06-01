#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<int, int>> q;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 0));
    
    q.push({0, 0});
    dist[0][0] = 1;
    
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && maps[nr][nc] != 0)
            {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
                maps[nr][nc] = 0;
            }
        }
    }
    
    if (dist[n-1][m-1] < 1) return -1;
    
    answer = dist[n-1][m-1];
    return answer;
}