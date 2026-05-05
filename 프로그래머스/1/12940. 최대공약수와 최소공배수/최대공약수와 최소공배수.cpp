#include <string>
#include <vector>

using namespace std;
int gcd(int a, int b);

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcdn = gcd(n, m);
    
    answer.push_back(gcdn);
    answer.push_back(n * m / gcdn);
    
    return answer;
}

int gcd(int a, int b)
{
    if (b == 0) return a;
    
    return gcd(b, a % b);
}