#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    answer = health;
    int prev_a = 0;
    
    for (const auto& a : attacks)
    {
        answer += (a[0]-(prev_a+1)) * bandage[1];
        
        answer += bandage[2] * ((a[0] - (prev_a+1)) / bandage[0]);
        
        if (answer > health) answer = health;
        
        answer -= a[1];
        
        if (answer <= 0) return -1;
        
        prev_a = a[0];
    }
    
    return answer;
}