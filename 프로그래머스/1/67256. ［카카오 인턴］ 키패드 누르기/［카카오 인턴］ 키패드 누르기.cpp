#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    vector<pair<int, int>> v;
    
    for (int i = 0; i <= 9; i++)
    {
        if (i == 0) v.push_back({3, 1});
        else v.push_back({(i-1)/3, (i-1)%3});
    }
    
    pair<int, int> lpos = {3, 0};
    pair<int, int> rpos = {3, 2};
    
    for (int n : numbers)
    {
        if (n == 1 || n == 4 || n == 7)
        {
            answer += 'L';
            lpos = v[n];
        }
        else if (n == 3 || n == 6 || n == 9)
        {
            answer += 'R';
            rpos = v[n];
        }
        else
        {
            int ldist = abs(lpos.first - v[n].first) + abs(lpos.second - v[n].second);
            int rdist = abs(rpos.first - v[n].first) + abs(rpos.second - v[n].second);
            
            if (ldist < rdist) 
            {
                answer += 'L';
                lpos = v[n];
            }
            else if (ldist > rdist) 
            {
                answer += 'R';
                rpos = v[n];
            }
            else 
            {
                if (hand == "left")
                {
                    answer += 'L';
                    lpos = v[n];
                }
                else
                {
                    answer += 'R';
                    rpos = v[n];
                }
            }
        }
    }
    
    return answer;
}