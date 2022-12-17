#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);

    while (1) {
        if (pq.top() < K && pq.size() == 1) {
            answer = -1;
            break;
        }
        if (pq.top() >= K)
            break;

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int tmp = first + second * 2;
        pq.push(tmp);

        answer++;
    }
    return answer;
}