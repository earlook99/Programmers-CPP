#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++)
    {
        int res = arr1[i] | arr2[i];
        
        int a = 1 << (n-1);
        string newrow = "";
        
        for (int j = 0; j < n; j++)
        {
            if ((a & res) > 0)
                newrow += '#';
            else
                newrow += ' ';
            
            a = a >> 1;
        }
        
        answer.push_back(newrow);
    }
    
    return answer;
}