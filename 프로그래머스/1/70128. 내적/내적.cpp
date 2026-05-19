#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 1234567890;
    answer = 0;
    
    for (int i = 0; i < a.size(); i++)
    {
        answer += a[i] * b[i];
    }
    
    return answer;
}