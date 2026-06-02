#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int prev = 2, prevprev = 1;
    int tmp;
    
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    for (int i = 3; i <= n; i++)
    {
        tmp = prev;
        prev = (prev + prevprev) % 1000000007;
        prevprev = tmp;
    }
    
    answer = prev;
    
    return answer;
}