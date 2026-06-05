#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int k = 1;; k++)
    {
        int ka = n - k*(k-1)/2;
        if (ka <= 0) break;
        if (ka % k == 0) answer++;
    }
    
    return answer;
}