#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    
    string people = "ACFJMNRT";
    do {
        bool isOK = true;
        for (const auto& d : data)
        {
            int idx1 = people.find(d[0]);
            int idx2 = people.find(d[2]);
            char op = d[3];
            int num = d[4]-'0';
            
            switch (op)
            {
                case '=':
                    if (abs(idx1-idx2)-1 != num) isOK = false;
                    break;
                case '>':
                    if (abs(idx1-idx2)-1 <= num) isOK = false;
                    break;
                case '<':
                    if (abs(idx1-idx2)-1 >= num) isOK = false;
                    break;
                default:
                    break;
            }
            if (!isOK) break;
        }
        if (isOK) answer++;
    } while (next_permutation(people.begin(), people.end()));
    
    return answer;
}