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
        if (tmp >= q.front()) { //앞에 나보다 더 값이 작은 애들이 있으면 그걸 세서 넣기
            count++;
            printf("%d가 %d보다 작기 때문에 같이 나온다. \n", q.front(), tmp);
            q.pop();


        }
        tmp = q.front();
        answer.push_back(count);
    }
    return answer;
}