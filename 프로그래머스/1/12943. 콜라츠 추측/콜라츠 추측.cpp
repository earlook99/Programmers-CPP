#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    if (num == 1) return 0;
    
    long long n = num;
    int i = 0;
    while (i <= 500)
    {
        i++;
        if (n % 2 == 0) n /= 2;
        else 
        {
            n *= 3;
            n++;
        }
        
        if (n == 1) return i;
    }
    
    return -1;
    
    return answer;
}