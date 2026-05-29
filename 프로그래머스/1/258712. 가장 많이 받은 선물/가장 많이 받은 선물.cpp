#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, int> id;
    int give[50][50] = {0};
    vector<int> v(friends.size(), 0);
    vector<int> giftIndex(friends.size(), 0);
    
    for (int i = 0; i < friends.size(); i++)
    {
        id[friends[i]] = i;
    }
    
    for (const auto& g : gifts)
    {
        stringstream ss(g);
        string first, second;
        ss >> first >> second;
        
        give[id[first]][id[second]]++;
    }
    
    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = 0; j < friends.size(); j++)
        {
            if (i == j) continue;
            
            giftIndex[i] += give[i][j];
            giftIndex[j] -= give[i][j];
        }
    }
    
    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = i+1; j < friends.size(); j++)
        {
            if (give[i][j] > give[j][i])
            {
                v[i]++;
            }
            else if (give[i][j] < give[j][i])
            {
                v[j]++;
            }
            else
            {
                if (giftIndex[i] > giftIndex[j])
                {
                    v[i]++;
                }
                else if (giftIndex[i] < giftIndex[j])
                {
                    v[j]++;
                }
            }
        }
    }
    
    answer = *max_element(v.begin(), v.end());
    
    return answer;
}