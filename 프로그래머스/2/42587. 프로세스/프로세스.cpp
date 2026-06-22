#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while (!q.empty())
    {
        if (q.front().first < pq.top())
        {
            q.push(q.front());
            q.pop();
        }
        
        else if (q.front().first == pq.top())
        {
            answer++;
            if (q.front().second == location) break;
            q.pop();
            pq.pop();
        }
    }
    
    return answer;
}