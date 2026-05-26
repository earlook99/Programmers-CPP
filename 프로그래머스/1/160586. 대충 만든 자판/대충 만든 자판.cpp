#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for (const string& t : targets)
    {
        int a = 0;
        
        for (const char& c : t)
        {
            int m = 101;
            
            for (const string& k : keymap)
            {
                auto idx = k.find(c);
                if (idx == string::npos) idx = 101;
                
                m = min(m, (int)idx + 1);
            }
            
            if (m == 101)
            {
                a = -1;
                break;
            }
            
            a += m;
        }
        
        answer.push_back(a);
    }
    
    return answer;
}