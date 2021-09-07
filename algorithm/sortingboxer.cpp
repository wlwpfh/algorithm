#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    int size = weights.size();
    vector<double> winPercent(size);

    vector<int> winMoreWeight(size);
    int i, j, win_count = 0, lose_count = 0;
    printf("%d \n", weights.size());

    for (i = 0; i < weights.size(); i++) {
        printf("%d ", weights[i]);
    }
    printf("\n");
    for (i = 0; i < weights.size(); i++) { //�� 
        for (j = 0; j < weights.size(); j++) { //���
            if (i == j) {
                ; //���� �� 
            }
            else {
                if (head2head[i][j] == 'W') {
                    win_count++;
                    if (weights[i] < weights[j]) { //�̰�µ� ��밡 �� ���԰� ������ ���
                        winMoreWeight[i]++;
                    }
                }
                else if (head2head[i][j] == 'L') {
                    lose_count++;
                }
            }
            if (win_count == 0 && lose_count == 0) {
                winPercent[i] = 0;
            }
            else {
                winPercent[i] += win_count / (win_count + lose_count) * 100;
            }
        }
    }

    for (i = 0; i < weights.size(); i++) {
        printf("%d�� �·��� %d�̰� �����Ժ��� �� ���ſ� ������ �̱� Ƚ���� %d \n",
            weights[i], winPercent[i], winMoreWeight[i]);
    }

    return answer;
}