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
    //n개가 다 찬 경우
     //printf("현재 counts:%d \n",counts);
    if (numbers == number) {
        counts++;
        //다 넣기
        if (counts == index)
            answer = tmp;
        if (answer.size() != 0)
            return;
        return;
    }
    //아직인 경우
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