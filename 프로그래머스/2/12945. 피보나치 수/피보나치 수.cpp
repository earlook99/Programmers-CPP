#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    long long a = 0;
    long long b = 1;
    
    for (int i = 2; i <= n; i++)
    {
        long long tmp = (a + b) % 1234567;
        a = b;
        b = tmp;
    }
    
    answer = b;
    
    return answer;
}