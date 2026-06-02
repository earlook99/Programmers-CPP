#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    const string d = "124";
    
    while (n > 0)
    {
        int m = (n-1) % 3;
        answer += d[m];
        n = (n-1) / 3;
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}