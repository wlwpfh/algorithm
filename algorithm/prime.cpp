#include <vector>
#include <iostream>
#include <string>
using namespace std;

int solution(vector<int> nums) {
    int i, j, k, h, sum, answer = 0;
    bool isPrime;

    for (i = 0; i <= nums.size() - 3; i++) {
        for (j = i + 1; j <= nums.size() - 2; j++) {
            for (k = j + 1; k <= nums.size() - 1; k++) {
                sum = nums[i] + nums[j] + nums[k];
                //printf("%d ",sum);
                isPrime = true;
                for (h = 2; h <= sum / 2; h++) {
                    if (sum % h == 0) {
                        isPrime = false;
                        //printf("¼Ò¼öX ");
                    }
                }

                if (isPrime == true) {
                    answer++;
                }
                //printf("%d ",answer);
            }
        }
    }

    return answer;
}