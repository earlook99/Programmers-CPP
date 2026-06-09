#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (true)
    {
        answer++;
        
        if ((a-1)/2 == (b-1)/2) break;
        
        a = (a-1) / 2 + 1;
        b = (b-1) / 2 + 1;
    }

    return answer;
}