#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct st
{
    string file;
    string head;
    int number;
};

bool cmp(const st& a, const st& b)
{
    if (a.head == b.head)
    {
        return a.number < b.number;
    }
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<st> v;
    
    for (auto& f : files)
    {
        int idx = 0;
        while (!isdigit(f[idx])) idx++;
        string head = f.substr(0, idx);
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        int numstart = idx;
        while (isdigit(f[idx])) idx++;
        int number = stoi(f.substr(numstart, idx-numstart));
        
        v.push_back({f, head, number});
    }
    
    stable_sort(v.begin(), v.end(), cmp);
    
    for (auto& a : v)
    {
        answer.push_back(a.file);
    }
    
    return answer;
}