#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++)
    {
        int j = 1;
        while (j*j < i) j++;
        
        if (j*j == i) answer -= i;
        else answer += i;
    }
    
    return answer;
}