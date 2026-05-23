#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<int>());
    
    int i = m;
    
    while (i <= score.size())
    {
        answer += score[i-1] * m;
        i += m;
    }
    
    return answer;
}