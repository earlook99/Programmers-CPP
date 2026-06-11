#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    for (int i = 0; i < bridge_length; i++) q.push(0);
    reverse(truck_weights.begin(), truck_weights.end());
    
    int s = 0;
    while (!truck_weights.empty() || s != 0)
    {
        s -= q.front();
        q.pop();
        
        int nxt = truck_weights.empty() ? 0 : truck_weights.back();
        
        if (s + nxt > weight || truck_weights.empty())
        {
            q.push(0);
        }
        else
        {
            q.push(nxt);
            s += nxt;
            truck_weights.pop_back();
        }
        
        answer++;
    }
    
    return answer;
}