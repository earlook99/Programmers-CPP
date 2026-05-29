#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    
    sort(mats.begin(), mats.end(), greater<int>());
    
    for (const auto& m : mats)
    {
        for (int i = 0; i < park.size(); i++)
        {
            if (i + m > park.size()) continue;
            
            for (int j = 0; j < park[0].size(); j++)
            {
                if (j + m > park[0].size()) continue;
                
                if (park[i][j] == "-1")
                {
                    bool isOK = true;
                    for (int k = 0; k < m; k++)
                    {
                        for (int l = 0; l < m; l++)
                        {
                            if (park[i+k][j+l] != "-1")
                            {
                                isOK = false;
                                break;
                            }
                        }
                        if (isOK == false) break;
                    }
                    if (isOK) return m;
                }
            }
        }
    }
    
    answer = -1;
    return answer;
}