#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int i, j, answer = 0;
    int checked[30] = { 0 }; //������ ���� ��
    int checking[30] = { 0 }; //������ ��
    for (i = 0; i < lost.size(); i++) {
        printf("���� ����� %d \n", lost[i]);

        for (j = 0; j < reserve.size(); j++) {
            printf("������ �� �ִ� ����� %d \n", reserve[j]);

            if (abs(lost[i] - reserve[j]) == 1 && checked[lost[i]] == 0
                && checking[reserve[j]] == 0) {
                checked[lost[i]] = 1;
                checking[reserve[j]] = 1;
                answer++;

                printf("%d�� �԰� �Ǿ��� \n", lost[i]);
            }
            else {
                printf("���� �����־��ų� ����� ���� �ʴ�. \n");
            }
        }

    }

    return n - lost.size() + answer;
}