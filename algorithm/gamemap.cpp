#include<vector>
#include <stdio.h>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

queue <pii> q;
int N, M;
vector<vector<int> > v;
void BFS() {
    int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (v[nx][ny] == 0)
                continue;

            if (v[nx][ny] == 1) {
                q.push(make_pair(nx, ny));
                v[nx][ny] = v[now.first][now.second] + 1;

            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    v = maps;
    N = maps.size();
    M = maps[N - 1].size();

    BFS();

    if (v[N - 1][M - 1] == 1)
        return -1;
    else
        return v[N - 1][M - 1];

}