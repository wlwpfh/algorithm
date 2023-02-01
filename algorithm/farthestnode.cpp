#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[50001];
int dis[20001];
int max_depth = 0;
void BFS(int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            if (dis[v[now][i]] == 0 && v[now][i] != 1) {
                dis[v[now][i]] = dis[now] + 1;
                max_depth = max(dis[v[now][i]], max_depth);
                q.push(v[now][i]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    sort(edge.begin(), edge.end());

    for (int i = 0; i < edge.size(); i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }

    BFS(1);

    for (int i = 0; i <= n; i++) {
        if (max_depth == dis[i])
            answer++;
    }

    return answer;
}