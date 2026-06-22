#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    int idx = 0;
    for (int i = 0; i <= citations.size(); i++)
    {
        while (idx < citations.size() && citations[idx] < i) idx++;
        int cnt = citations.size() - idx;
        if (cnt >= i) answer = max(i, answer);
    }
    
    return answer;
}