#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int a = n + (n & (-n));
    int b = __builtin_popcount(n) - __builtin_popcount(a);
    a += (1 << b)-1;
    answer = a;
    
    return answer;
}