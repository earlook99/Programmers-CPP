#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    unordered_set<string> st;
    vector<pair<string, bool>> v;
    
    string word = "";
    bool isSpoiler = false;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == ' ') 
        {
            v.push_back(make_pair(word, isSpoiler));
            word = "";
            isSpoiler = false;
        }
        else
        {
            for (const auto& s : spoiler_ranges)
                if (i >= s[0] && i <= s[1]) isSpoiler = true;
            word += message[i];
        }
    }
    if (!word.empty()) v.push_back(make_pair(word, isSpoiler));
    
    for (const auto& v1 : v)
        if (!v1.second) st.insert(v1.first);
    
    for (const auto& v1 : v)
        if (v1.second && st.count(v1.first) == 0)
        {
            answer++;
            st.insert(v1.first);
        }
    
    return answer;
}