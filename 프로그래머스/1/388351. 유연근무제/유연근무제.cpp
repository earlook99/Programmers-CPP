#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for (int i = 0; i < schedules.size(); i++)
    {
        schedules[i] = schedules[i]/100*60 + schedules[i]%100;
    }
    
    for (auto& t : timelogs)
    {
        for (int i = 0; i < t.size(); i++)
        {
            t[i] = t[i]/100*60 + t[i]%100;
        }
    }
    
    for (int i = 0; i < timelogs.size(); i++)
    {
        bool isOK = true;
        
        for (int j = 0; j < timelogs[0].size(); j++)
        {
            if (startday != 6 && startday != 7 && schedules[i]+10 < timelogs[i][j]) isOK = false;
            
            startday = (startday % 7) + 1;
        }
        
        if (isOK) answer++;
    }
    
    return answer;
}