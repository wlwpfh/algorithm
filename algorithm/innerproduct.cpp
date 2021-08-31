#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a_len은 배열 a의 길이입니다.
// b_len은 배열 b의 길이입니다.
int solution(int a[], size_t a_len, int b[], size_t b_len) {
    int i, answer = 0;
    for (i = 0; i < a_len; i++) {
        answer = answer + (a[i] * b[i]);
    }

    return answer;
}