#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (auto& t : skill_trees)
    {
        int idx = 0;
        bool isWrong = false;
        for (auto& s : t)
        {
            if (idx < skill.length() && s == skill[idx]) idx++;
            else if (skill.find(s) != string::npos)
            {
                isWrong = true;
                break;
            }
        }
        if (isWrong) continue;
        answer++;
    }
    
    return answer;
}