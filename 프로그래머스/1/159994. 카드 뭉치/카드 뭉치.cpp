#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int c1idx = 0;
    int c2idx = 0;
    
    answer = "Yes";
    
    for (const string& g : goal)
    {
        if (c1idx < cards1.size() && g == cards1[c1idx])
        {
            c1idx++;
        }
        else if (c2idx < cards2.size() && g == cards2[c2idx])
        {
            c2idx++;
        }
        else
        {
            answer = "No";
            break;
        }
    }
    
    return answer;
}