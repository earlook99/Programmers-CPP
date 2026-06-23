#include <string>
#include <vector>

using namespace std;

int sz;
int tgt;
int answer;
vector<int> nms;

void dfs(int idx, int sum)
{
    if (idx == sz)
    {
        if (sum == tgt) answer++;
        return;
    }
    
    dfs(idx + 1, sum + nms[idx]);
    dfs(idx + 1, sum - nms[idx]);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    sz = numbers.size();
    tgt = target;
    nms = numbers;
    
    dfs(0, 0);
    
    return answer;
}