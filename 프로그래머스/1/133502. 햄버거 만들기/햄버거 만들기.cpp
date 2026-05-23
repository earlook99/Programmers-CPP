#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0; 
    vector<int> v;
    int n = 0;
    
    for (const int& i : ingredient)
    {
        v.push_back(i);
        n++;
        
        if (n >= 4 && v[n-4] == 1 && v[n-3] == 2 && v[n-2] == 3 && v[n-1] == 1)
        {
            v.pop_back();
            v.pop_back();
            v.pop_back();
            v.pop_back();
            n -= 4;
            answer++;
        }
    }
    
    return answer;
}