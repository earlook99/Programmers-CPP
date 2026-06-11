#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> st;
    
    for (auto& p : phone_book)
        st.insert(p);
    
    for (auto& p : phone_book)
        for (int i = 1; i < p.length(); i++)
            if (st.count(p.substr(0, i)) > 0)
                return false;
    
    
    return answer;
}