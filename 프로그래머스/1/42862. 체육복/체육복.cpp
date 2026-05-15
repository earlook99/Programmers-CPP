#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> cnt(n, 1);
    
    for (int& l : lost)
        cnt[l-1]--;
    
    for (int& r : reserve)
        cnt[r-1]++;
    
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == 0)
        {
            if (i != 0 && cnt[i-1] >= 2)
            {
                cnt[i-1]--;
                cnt[i]++;
                continue;
            }
            else if (i != n-1 && cnt[i+1] >= 2)
            {
                cnt[i+1]--;
                cnt[i]++;
                continue;
            }
        }
    }
    
    for (int& c : cnt)
    {
        if (c >= 1) answer++;
    }
    
    return answer;
}