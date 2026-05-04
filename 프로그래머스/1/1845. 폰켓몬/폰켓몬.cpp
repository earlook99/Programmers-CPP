#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int cnt = nums.size()/2;
    
    set<int> s(nums.begin(), nums.end());
    
    answer = min(cnt, (int)s.size());
    
    return answer;
}