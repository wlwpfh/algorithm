#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len�� �迭 lottos�� �����Դϴ�.
// win_nums_len�� �迭 win_nums�� �����Դϴ�.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.

    int i, j, zero_count = 0, match_count = 0;
    for (i = 0; i < lottos_len; i++) {
        if (lottos[i] == 0) {
            zero_count++;
        }
    }

    for (i = 0; i < lottos_len; i++) {
        for (j = 0; j < win_nums_len; j++) {
            if (lottos[i] == win_nums[j]) {
                match_count++;
            }
        }
    }



    int* answer = (int*)malloc(1);

    answer[0] = 7 - (match_count + zero_count);
    answer[1] = 7 - (match_count);

    if (answer[0] > 6) {
        answer[0] = 6;
    }
    if (answer[1] > 6) {
        answer[1] = 6;
    }

    return answer;
}