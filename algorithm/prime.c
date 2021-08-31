#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int i, j, k, h, sum, answer = 0;
    bool isPrime = true;


    for (i = 0; i <= nums_len - 3; i++) {
        for (j = i + 1; j <= nums_len - 2; j++) {
            for (k = j + 1; k <= nums_len - 1; k++) {
                sum = nums[i] + nums[j] + nums[k];
                printf("%d ", sum);

                for (h = 2; h <= sum / 2; h++) {
                    if (sum % h == 0) {
                        isPrime = false;
                        break;
                    }
                }

                if (isPrime == true) {
                    answer = answer + 1;
                }
            }
        }
    }

    return answer;
}