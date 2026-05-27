#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> pos;
    
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[0].length(); j++)
        {
            if (park[i][j] == 'S')
            {
                pos = make_pair(i, j);
            }
        }
    }
    
    int H = park.size();
    int W = park[0].length();
    
    for (const string& r : routes)
    {
        int dr = 0, dc = 0;
        switch (r[0])
        {
            case 'E': dr = 0; dc = +1; break;
            case 'W': dr = 0; dc = -1; break;
            case 'S': dr = +1; dc = 0; break;
            case 'N': dr = -1; dc = 0; break;
        }
        
        int steps = r[2] - '0';
        pair<int, int> origin = pos;
        
        for (int i = 0; i < steps; i++)
        {
            pos.first += dr;
            pos.second += dc;
            
            if (pos.first < 0 || pos.first >= H
             || pos.second < 0 || pos.second >= W
             || park[pos.first][pos.second] == 'X')
            {
                pos = origin;
                break;
            }
        }
    }
    
    answer.push_back(pos.first);
    answer.push_back(pos.second);
    
    return answer;
}