#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int r = (num-1) / w;
    int p = (num-1) % w;
    int c;
    
    if (r % 2 == 0) c = p;
    else c = (w-1) - p;
    
    int cur = num;
    
    while(cur <= n)
    {
        r++;
        if (r % 2 == 0)
        {
            cur = r*w + 1 + c;
        }
        else
        {
            cur = (r+1)*w - c;
        }
        answer++;
    }
    
    
    return answer;
}