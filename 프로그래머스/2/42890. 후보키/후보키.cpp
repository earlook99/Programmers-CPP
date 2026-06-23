#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> keys;
    int len = relation[0].size();
    
    for (int mask = 1; mask < (1 << len); mask++)
    {
        bool isDup = false;
        for (auto& k : keys)
        {
            isDup = ((k & mask) == k);
            if (isDup) break;
        }
        if (isDup) continue;
        
        set<vector<string>> st;
        for (int i = 0; i < relation.size(); i++)
        {
            vector<string> v;
            for (int j = 0; j < len; j++)
            {
                if (mask & (1 << j)) v.push_back(relation[i][j]);
            }
            st.insert(v);
        }
        
        if (relation.size() == st.size())
        {
            answer++;
            keys.push_back(mask);
        }
    }
    
    return answer;
}