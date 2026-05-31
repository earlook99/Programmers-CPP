#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 1;
    
    for (const auto& a : arr)
    {
        answer = lcm(answer, a);
    }
    
    return answer;
}