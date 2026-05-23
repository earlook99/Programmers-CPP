#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> words = {"aya", "ye", "woo", "ma"};
    
    for (const string& b : babbling)
    {
        int idx = 0;
        string prev = "";
        
        while (idx <= b.length() - 1)
        {
            bool isMatched = false;
            
            for (const string& w : words)
            {
                if (b.substr(idx, w.length()) == w && w != prev)
                {
                    isMatched = true;
                    prev = w;
                    idx += w.length();
                    break;
                }
            }
            
            if (!isMatched) break;
        }
        
        if (idx >= b.length()) answer++;
    }
    
    return answer;
}