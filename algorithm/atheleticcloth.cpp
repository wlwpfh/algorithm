#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int i, j, answer = 0;
    int checked[30] = { 0 }; //빌림을 받은 애
    int checking[30] = { 0 }; //빌려준 애
    for (i = 0; i < lost.size(); i++) {
        printf("없는 사람은 %d \n", lost[i]);

        for (j = 0; j < reserve.size(); j++) {
            printf("빌려줄 수 있는 사람은 %d \n", reserve[j]);

            if (abs(lost[i] - reserve[j]) == 1 && checked[lost[i]] == 0
                && checking[reserve[j]] == 0) {
                checked[lost[i]] = 1;
                checking[reserve[j]] = 1;
                answer++;

                printf("%d는 입게 되었다 \n", lost[i]);
            }
            else {
                printf("누가 빌려주었거나 사이즈가 맞지 않다. \n");
            }
        }

    }

    return n - lost.size() + answer;
}