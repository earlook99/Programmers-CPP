#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> st;
    
    int idx = 1;
    int turn = 1;
    char prev = words[0][0];
    for (auto& w : words)
    {
        if (st.count(w) >= 1) break;
        if (prev != w[0]) break;
        st.insert(w);
        prev = w.back();
        idx = idx % n + 1;
        if (idx == 1) turn++;
    }
    
    if (n * (turn - 1) + idx - 1 == words.size()) 
    {
        idx = 0;
        turn = 0;
    }
    
    answer.push_back(idx);
    answer.push_back(turn);

    return answer;
}