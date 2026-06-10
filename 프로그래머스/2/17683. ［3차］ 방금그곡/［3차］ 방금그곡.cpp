#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

int shigan(string start, string end)
{
    int st = stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2));
    int en = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2));
    return en - st;
}

string convert(string s) 
{
    string res = "";
    for (int i = 0; i < s.size(); i++) 
    {
        if (i + 1 < s.size() && s[i + 1] == '#') 
        {
            res += tolower(s[i]);
            i++;
        } 
        else 
        {
            res += s[i];
        }
    }
    return res;
}

string solution(string m, vector<string> musicinfos) 
{
    m = convert(m);
    string answer = "(None)";
    int best = -1;

    for (auto& info : musicinfos) 
    {
        stringstream ss(info);
        string token;
        vector<string> field;
        while (getline(ss, token, ',')) field.push_back(token);

        int sg = shigan(field[0], field[1]);
        string melody = convert(field[3]);

        string music = "";
        for (int i = 0; i < sg; i++)
            music += melody[i % melody.size()];

        if (music.find(m) != string::npos && sg > best) 
        {
            best = sg;
            answer = field[2];
        }
    }
    return answer;
}