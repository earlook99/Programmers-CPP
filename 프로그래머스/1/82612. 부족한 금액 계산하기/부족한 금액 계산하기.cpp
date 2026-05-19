using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    answer = ((long long)(count+1) * count / 2 * price) - money;
    if (answer <= 0) answer = 0;

    return answer;
}