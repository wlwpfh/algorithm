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
    for (i = 0; i < weights.size(); i++) { //�� 
        win_count = 0; lose_count = 0;
        for (j = 0; j < weights.size(); j++) { //���

            if (i == j) {
                ; //���� �� 
            }
            else {
                if (head2head[i][j] == 'W') {
                    win_count++;
                    if (weights[i] < weights[j]) { //�̰�µ� ��밡 �� ���԰� ������ ���
                        winMoreWeight[i]++;
                        printf("%d�� ���ſ� �� �̱� Ƚ�� : %d\n"
                            , weights[i], winMoreWeight[i]);
                    }
                }
                else if (head2head[i][j] == 'L') {
                    lose_count++;
                }
                else {
                    no++;
                }
                //printf("��:%d, ������� �̱� Ƚ��:%d, �� Ƚ��: %d, ��� Ƚ��: %d \n",weights[i],win_count,lose_count,no);
            }
            if (win_count == 0 && lose_count == 0) {
                winPercent[i] = winPercent[i] + 0;
            }
            else {
                winPercent[i] = win_count / (weights.size() - no);
            }

            printf("%d�� �·��� %f \n", weights[i], winPercent[i]);
        }
    }

    // for(i=0;i<weights.size();i++){
    //     printf("%d�� �·��� %d�̰� �����Ժ��� �� ���ſ� ������ �̱� Ƚ���� %d \n",
    //            weights[i],winPercent[i],winMoreWeight[i]);
    // }

    return answer;
}