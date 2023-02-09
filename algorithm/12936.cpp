#include <string>
#include <vector>

using namespace std;

bool visited[20];

vector<int> answer;
vector<int> tmp;
long long index; //k
int number; //n 
long long counts;

void getLine(int numbers, int num) {
    //n���� �� �� ���
     //printf("���� counts:%d \n",counts);
    if (numbers == number) {
        counts++;
        //�� �ֱ�
        if (counts == index)
            answer = tmp;
        if (answer.size() != 0)
            return;
        return;
    }
    //������ ���
    for (int i = 1; i <= number; i++) {
        if (!visited[i]) {
            visited[i] = true;
            tmp.push_back(i);
            getLine(numbers + 1, num + 1);
            tmp.pop_back();
            visited[i] = false;
        }
    }
}

vector<int> solution(int n, long long k) {
    index = k;
    number = n;

    findStart(n, k);

    getLine(0, 1);

    return answer;
}