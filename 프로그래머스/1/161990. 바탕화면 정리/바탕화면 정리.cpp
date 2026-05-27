#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int lux = INT_MAX;
    int luy = INT_MAX;
    int rdx = INT_MIN;
    int rdy = INT_MIN;
    
    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[0].length(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if (lux > i) lux = i;
                if (rdx < i) rdx = i;
                if (luy > j) luy = j;
                if (rdy < j) rdy = j;
            }
        }
    }
    
    rdx++;
    rdy++;
    
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);
    
    return answer;
}