#include <string>
#include <vector>
#include <set>

using namespace std;

int answer = 0;
set<int> seen;

bool is_prime(const int& n)
{
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    
    return true;
}

void backtrack(string& numbers, vector<bool>& used, string cur)
{
    if (cur != "")
    {
        int x = stoi(cur);
        if (seen.insert(x).second && is_prime(x)) answer++;
    }
    
    for (int i = 0; i < numbers.size(); i++)
    {
        if (used[i]) continue;
        used[i] = true;
        backtrack(numbers, used, cur + numbers[i]);
        used[i] = false;
    }
}

int solution(string numbers) {
    answer = 0;
    seen.clear();
    vector<bool> used(numbers.size(), false);
    
    backtrack(numbers, used, "");
    
    return answer;
}