#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    
    stringstream ss(s);
    int x;
    while (ss >> x) v.push_back(x);
    
    answer += to_string(*min_element(v.begin(), v.end()));
    answer += ' ';
    answer += to_string(*max_element(v.begin(), v.end()));
    
    return answer;
}