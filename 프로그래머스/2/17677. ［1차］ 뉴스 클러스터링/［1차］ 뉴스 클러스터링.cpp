#include <string>
#include <set>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> s1;
    multiset<string> s2;
    vector<string> inter, uni;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for (int i = 0; i+1 < str1.size(); i++)
    {
        if (isalpha(str1[i]) && isalpha(str1[i+1]))
        {
            string token = str1.substr(i, 2);
            s1.insert(token);
        }
    }
    
    for (int i = 0; i+1 < str2.size(); i++)
    {
        if (isalpha(str2[i]) && isalpha(str2[i+1]))
        {
            string token = str2.substr(i, 2);
            s2.insert(token);
        }
    }
    
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(inter));
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(uni));
    
    answer = uni.empty() ? 65536 : inter.size() * 65536 / uni.size();
    
    return answer;
}