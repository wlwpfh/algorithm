#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int i, tmp, a, count = 0;

    for (i = 0; i < progresses.size(); i++) {
        tmp = 100 - progresses[i];
        if (tmp % speeds[i] == 0)
            q.push(tmp / speeds[i]);
        else
            q.push(tmp / speeds[i] + 1);
    }
    tmp = q.front();
    while (!q.empty()) {
        count = 0;

        q.pop();
        count++;
        if (tmp >= q.front()) { //�տ� ������ �� ���� ���� �ֵ��� ������ �װ� ���� �ֱ�
            count++;
            printf("%d�� %d���� �۱� ������ ���� ���´�. \n", q.front(), tmp);
            q.pop();


        }
        tmp = q.front();
        answer.push_back(count);
    }
    return answer;
}