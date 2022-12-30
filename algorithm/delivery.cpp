#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

struct Town {
    int x;  int value;
    Town(int a, int b) {
        x = a;
        value = b;
    }
    bool operator<(const Town& t)const {
        return value < t.value;
    }
};
vector<Town> v[51];

int dis[51];
priority_queue<Town> pq;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 1; i <= N; i++)
        dis[i] = INF;

    for (int i = 0; i < road.size(); i++) {
        v[road[i][0]].push_back(Town(road[i][1], road[i][2]));
        v[road[i][1]].push_back(Town(road[i][0], road[i][2]));
    }

    dis[1] = 0;

    pq.push(Town(1, 0));

    while (!pq.empty()) {
        Town now = pq.top();
        pq.pop();

        for (int i = 0; i < v[now.x].size(); i++) {
            Town next = v[now.x].at(i);

            if (dis[next.x] > dis[now.x] + next.value) {
                dis[next.x] = dis[now.x] + next.value;
                pq.push(Town(next.x, dis[next.x]));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dis[i] <= K)
            answer++;
    }

    return answer;
}