#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long tmp = n;
    int i, j, count = 0, array[10] = { 0 };

    while (tmp > 0) {
        array[tmp % 10]++;
        tmp = tmp / 10;
        count++;
    }
    for (i = 9; i >= 0; i--) {
        if (array[i] != 0) {
            for (j = 0; j < array[i]; j++) {
                answer += pow(10, count - 1) * i;
                printf("answer: %d \n", answer);
                count--;
            }
        }
        else {
            ;
        }
    }
    return answer;
}