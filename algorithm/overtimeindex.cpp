#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());

    for (int i = 0; i < n; i++) {
        if (pq.top() > 0) {
            int tmp = pq.top();
            pq.pop();
            pq.push(tmp - 1);
        }
    }

    while (!pq.empty()) {
        answer += pq.top() * pq.top();
        pq.pop();
    }

    return answer;
}