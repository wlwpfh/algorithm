#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    int size = weights.size();
    vector<double> winPercent(size);

    vector<int> winMoreWeight(size);
    int i, j, win_count = 0, lose_count = 0;
    //printf("%d \n",weights.size());

    for (i = 0; i < weights.size(); i++) {
        printf("%d ", weights[i]);
    }
    printf("\n");
    for (i = 0; i < weights.size(); i++) { //나 
        win_count = 0; lose_count = 0;
        for (j = 0; j < weights.size(); j++) { //상대

            if (i == j) {
                ; //나와 나 
            }
            else {
                if (head2head[i][j] == 'W') {
                    win_count++;
                    if (weights[i] < weights[j]) { //이겼는데 상대가 더 무게가 나가는 경우
                        winMoreWeight[i]++;
                        printf("%d가 무거운 놈 이긴 횟수 : %d\n"
                            , weights[i], winMoreWeight[i]);
                    }
                }
                else if (head2head[i][j] == 'L') {
                    lose_count++;
                }
                else {
                    no++;
                }
                //printf("나:%d, 현재까지 이긴 횟수:%d, 진 횟수: %d, 비긴 횟수: %d \n",weights[i],win_count,lose_count,no);
            }
            if (win_count == 0 && lose_count == 0) {
                winPercent[i] = winPercent[i] + 0;
            }
            else {
                winPercent[i] = win_count / (weights.size() - no);
            }

            printf("%d의 승률은 %f \n", weights[i], winPercent[i]);
        }
    }

    // for(i=0;i<weights.size();i++){
    //     printf("%d의 승률은 %d이고 몸무게보다 더 무거운 복서를 이긴 횟수는 %d \n",
    //            weights[i],winPercent[i],winMoreWeight[i]);
    // }

    return answer;
}