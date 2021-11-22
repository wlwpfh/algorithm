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
    q.pop();
    count = 1;
    while (1) {
        if (tmp >= q.front()) {
            count++;
            q.pop();
        }
        else {
            tmp = q.front();
            q.pop();
            answer.push_back(count);
            count = 1;

        }
        if (q.empty()) {
            answer.push_back(count);
            break;
        }
    }
    return answer;
}