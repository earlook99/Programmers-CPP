#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int painted_until = 0;
    
    for (const int& s : section)
    {
        if (s > painted_until)
        {
            answer++;
            painted_until = s + m - 1;
        }
    }
    
    return answer;
}