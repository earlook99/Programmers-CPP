#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, double>& a, const pair<int, double>& b)
{
    if (a.second == b.second) return a.first<b.first;
    return a.second>b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, double> mp;
    
    sort(stages.begin(), stages.end());
    
    int cnt = 1;
    
    for (int i = 0; i < stages.size(); i++)
    {
        if (i < stages.size()-1 && stages[i] == stages[i+1])
        {
            cnt++;
            continue;
        }
        
        mp[stages[i]] = (double)cnt/(stages.size()-i-1+cnt);
        cnt = 1;
    }
    
    for (int i = 1; i <= N; i++)
    {
        mp[i];
    }
    
    vector<pair<int, double>> v;
    for (auto& p : mp)
    {
        if (p.first > N) continue;
        v.push_back(p);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for (auto& a : v)
    {
        answer.push_back(a.first);
    }
    
    return answer;
}

