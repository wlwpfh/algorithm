#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int rest = 0, count = 0, new_count = 0;
    long long three_num = 0, tmp, new_three = 0, answer = 0;

    while (1) {
        if (n < 3) {
            three_num += pow(10, count) * n;
            count++;
            printf("3진법으로 %d \n", three_num);
            break;
        }
        else {
            rest = n % 3;
            n = n / 3;
            three_num += pow(10, count) * rest;
            count++;
            printf("3진법으로 %d \n", three_num);
        }

    }
    printf("%d %d \n", three_num, count);

    while (1) {
        if (new_count == count) {
            answer += three_num * 1;
            break;
        }
        else {
            tmp = three_num % 10;
            three_num = three_num / 10;
            new_count++;
            answer += pow(3, count - new_count) * tmp;
            printf("몫:%d 나머지:%d answer: %d count:%d \n", three_num, tmp, answer, new_count);

        }
    }

    return answer;
}