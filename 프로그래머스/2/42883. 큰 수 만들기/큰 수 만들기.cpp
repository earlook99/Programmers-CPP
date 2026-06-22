#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> st;
    
    for (auto& n : number)
    {
        while (!st.empty() && st.back() < n && k > 0)
        {
            st.pop_back();
            k--;
        }
        st.push_back(n);
    }
    
    while (k > 0)
    {
        st.pop_back();
        k--;
    }
    
    for (auto& s : st)
    {
        answer += s;
    }
    
    return answer;
}