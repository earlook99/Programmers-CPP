#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> dates;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        int q = (100 - progresses[i]) / speeds[i];
        dates.push_back((100 - progresses[i]) % speeds[i] > 0 ? q+1 : q);
    }
    
    int prev = dates[0];
    int cnt = 1;
    for (int i = 1 ; i < dates.size(); i++)
    {
        if (dates[i] <= prev)
        {
            cnt++;
        }
        else
        {
            prev = dates[i];
            answer.push_back(cnt);
            cnt = 1;
        }
    }
    
    answer.push_back(cnt);
    return answer;
}