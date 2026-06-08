#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<pair<int, int>>> graph(N + 1);
    for (auto& r : road)
    {
        int a = r[0], b = r[1], cost = r[2];
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
    
    vector<int> dist(N + 1, 1e9);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    while(!pq.empty())
    {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if (d > dist[cur]) continue;
        
        for (auto& g : graph[cur])
        {
            if (dist[g.first] > g.second + dist[cur])
            {
                dist[g.first] = g.second + dist[cur];
                pq.push({dist[g.first], g.first});
            }
        }
    }
    
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K) answer++;
    }

    return answer;
}