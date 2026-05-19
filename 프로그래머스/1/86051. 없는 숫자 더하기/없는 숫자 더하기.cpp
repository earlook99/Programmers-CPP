#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    
    int s = accumulate(numbers.begin(), numbers.end(), 0);
    
    answer = 45 - s;
    
    return answer;
}