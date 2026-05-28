#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    unordered_map<string, int> mp;
    vector<vector<int>> v;
    
    mp["code"] = 0;
    mp["date"] = 1;
    mp["maximum"] = 2;
    mp["remain"] = 3;
    
    for (const auto& d : data)
    {
        if (d[mp[ext]] < val_ext)
        {
            answer.push_back(d);
        }
    }
    
    int idx = mp[sort_by];
    sort(answer.begin(), answer.end(), [idx](const vector<int>& a, const vector<int>& b) { return a[idx] < b[idx]; });
    
    return answer;
}