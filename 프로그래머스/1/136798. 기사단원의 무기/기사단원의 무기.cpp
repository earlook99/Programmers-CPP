#include <string>
#include <vector>

using namespace std;

int yaksu(int n)
{
    int cnt = 0;
    bool isJegop = false;
    
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0) cnt++;
        if (i*i == n) isJegop = true;
    }
    return (isJegop? cnt*2-1 : cnt*2);
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++)
    {
        answer += yaksu(i) > limit ? power : yaksu(i);
    }
    
    return answer;
}
