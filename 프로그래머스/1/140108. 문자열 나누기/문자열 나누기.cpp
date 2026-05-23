#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int cnt = 0;
    char prev = s[0];
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == prev) cnt++;
        else cnt--;
        
        if (cnt == 0)
        {
            answer++;
            prev = s[i+1];
        }
    }
    
    if (cnt != 0) answer++;
    
    return answer;
}