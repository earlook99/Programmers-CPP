#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    auto stop = phone_number.end() - 4;
    
    for (auto it = phone_number.begin(); it != stop; it++) 
        *it = '*';
    
    answer = phone_number;
    
    return answer;
}