#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    int i = 0;
    while (!q.empty()) {
        // printf("q.front():%d, pq.top():%d, i:%d answer:%d \n",
           //    q.front(), pq.top(), i, answer);
        pair<int, int> tmp = q.front();
        if (tmp.second == pq.top()) {
            //ÀÎ¼âÇÏ´Â Áß
            pq.pop();
            q.pop();
            answer++;
            if (tmp.first == location)
                break;

        }
        else {
            pair<int, int> current = q.front();
            q.pop();
            q.push(current);
        }
        i++;
    }


    return answer;
}