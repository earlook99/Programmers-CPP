#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int cnt = brown + yellow;
    
    for (int i = 3; i*i <= cnt; i++)
    {
        if (cnt % i != 0) continue;
        
        int r = i;
        int c = cnt / r;
        
        if (yellow == (r-2) * (c-2))
        {
            answer.push_back(c);
            answer.push_back(r);
            break;
        }
    }
    
    return answer;
}