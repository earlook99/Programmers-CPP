#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    
    if (cacheSize == 0) return 5 * cities.size();
    
    for (auto& c : cities)
    {
        transform(c.begin(), c.end(), c.begin(), ::tolower);

        auto it = find(cache.begin(), cache.end(), c);
        if (it == cache.end())
        {
            answer += 5;
            if (cache.size() == cacheSize) cache.pop_front();
        }
        else
        {
            answer += 1;
            cache.erase(it);
        }
        
        cache.push_back(c);
    }
    
    
    return answer;
}