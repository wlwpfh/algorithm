#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int location_index = 0; //��ġ�� ���ϴϱ� 
    int tmp_max = 0;
    queue<int> q;
    int tmp_front;
    // queue<string> index;
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(priorities[i]);

        if (q.back() > tmp_max)
            tmp_max = q.back();
    }

    printf("tmp_max: %d ", tmp_max);
    while (1) {
        if (q.size() == 0) //�ش� ���� pop�Ǹ�
            break;
        else {
            //�տ� �ִ� �� ���� ������ �װ� ���� �ڷ� �ٽ� �ֱ�

            // ť �ȿ��� �� ���� ū ���� �� �� Ȯ���ؾ� ��



            if (q.front() == tmp_max)//���� ���� ���� ū ������
                q.pop();
            else {
                tmp_front = q.front();
                q.pop();
                q.push(tmp_front);
            }
        }
    }

    return answer;
}