#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> candidates(n);
    iota(candidates.begin(), candidates.end(), 1);
    
    vector<long long> fact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i-1] * i;
    
    k--;
    
    for (int i = 0; i < n; i++)
    {
        long long idx = k / fact[n-(i+1)];
        answer.push_back(candidates[idx]);
        candidates.erase(candidates.begin() + idx);
        k = k % fact[n-(i+1)];
    }
    
    return answer;
}