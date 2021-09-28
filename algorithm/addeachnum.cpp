#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int re = n, div = 0;

    while (re > 0) {
        div = re % 10;
        answer += div;
        re = re / 10;
    }

    return answer;
}