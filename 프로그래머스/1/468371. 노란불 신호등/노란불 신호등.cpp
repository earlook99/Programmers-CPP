#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) 
{
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}

int lcm(int a, int b) 
{
    return a * b / gcd(a, b);
}

int solution(vector<vector<int>> signals) {
    int answer = -1;
    int t = 1;
    
    int lc = signals[0][0] + signals[0][1] + signals[0][2];
    for (int i = 1; i < signals.size(); i++)
        lc = lcm(lc, signals[i][0] + signals[i][1] + signals[i][2]);
    
    while (t <= lc)
    {
        bool all_yellow = true;
        for (int i = 0; i < signals.size(); i++)
        {
            int cycle = signals[i][0] + signals[i][1] + signals[i][2];
            int p = (t-1) % cycle + 1;

            if (p < signals[i][0]+1 || p >signals[i][0]+signals[i][1])
            {
                all_yellow = false;
                break;
            }
        }
        if (all_yellow)
        {
            answer = t;
            break;
        }
        
        t++;
    }
    
    return answer;
}