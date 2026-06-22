#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    for (auto& s : scoville)
    {
        pq.push(s);
    }
    
    while (pq.top() < K)
    {
        if (pq.size() < 2) return -1;
        
        answer++;
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a + b * 2);
    }
    
    return answer;
}