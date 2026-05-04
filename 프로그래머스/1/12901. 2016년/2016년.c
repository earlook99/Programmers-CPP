#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    char* answer = (char*)malloc(sizeof(char) * 4);
    char* days[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int s = 0;
    for (int i = 0; i <= a-2; i++)
        s += months[i];
    
    strcpy(answer, days[(s + b - 1) % 7]);
    
    return answer;
}