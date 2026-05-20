#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    bool found = false;
    for (int i = 2; i*i <= n-1; i++) 
    {
        if (n % i == 1) 
        {
            answer = i;
            found = true;
            break;
        }
    }
    if (!found) 
    {
        answer = n-1;
    }
    
    return answer;
}