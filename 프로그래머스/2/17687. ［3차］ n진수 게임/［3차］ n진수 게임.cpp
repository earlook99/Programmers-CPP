#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string jinsu(int end, int n)
{
    const string D = "0123456789ABCDEF";
    string res = "0";
    for (int i = 1; i <= end; i++)
    {
        string tmp = "";
        int soo = i;
        while (soo > 0)
        {
            tmp += D[soo % n];
            soo /= n;
        }
        reverse(tmp.begin(), tmp.end());
        res += tmp;
    }
    
    return res;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string nums = "";
    
    nums = jinsu(t * m, n);
    
    int idx = p-1;
    while (idx <= p-1 + (t-1) * m)
    {
        answer += nums[idx];
        idx += m;
    }
    
    return answer;
}