#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for (long long i = begin; i <= end; i++)
    {
        long long block;
        if (i == 1) block = 0;
        else block = 1;
        for (long long j = 2; j*j <= i; j++)
        {
            if (i % j == 0)
            {
                if (i / j <= 10000000)
                {
                    block = i/j;
                    break;
                }
                else block = j;
            }
        }
        answer.push_back(block);
    }
    
    
    return answer;
}