#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    int n_1 = 1;
    int n_2 = 2;
    if (n == 1) return n_1;
    else if (n == 2) return n_2;
    
    for (int i = 3; i <= n; i++)
    {
        long long a = (n_1 + n_2) % 1234567;
        n_1 = n_2;
        n_2 = a;
    }
    
    answer = n_2;
    
    return answer;
}