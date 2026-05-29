#include <string>
#include <vector>

using namespace std;

int time_to_sec(string str)
{
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int vl = time_to_sec(video_len);
    int ps =  time_to_sec(pos);
    int os = time_to_sec(op_start);
    int oe = time_to_sec(op_end);
    
    for (const auto& c : commands)
    {
        if (ps < 0) ps = 0;
        if (ps > vl) ps = vl;
        if (ps >= os && ps <= oe) ps = oe;
        
        if (c == "next") ps += 10;
        if (c == "prev") ps -= 10;
    }
    
    if (ps < 0) ps = 0;
    if (ps > vl) ps = vl;
    if (ps >= os && ps <= oe) ps = oe;
    
    answer += to_string(ps / 60).length() == 1 ? "0" + to_string(ps / 60) : to_string(ps / 60);
    answer += ':';
    answer += to_string(ps % 60).length() == 1 ? "0" + to_string(ps % 60) : to_string(ps % 60);
    
    return answer;
}