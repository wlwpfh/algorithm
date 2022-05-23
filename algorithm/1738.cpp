#include<stdio.h>
#include<vector>
#include<queue>
#define INF 987654321

using namespace std;

int N, M;
struct Path {
	int x;
	int y;
	int money;
	Path(int a, int b, int c) {
		x = a; y = b; money = c;
	}
};
vector<Path> p[101];
vector<int> rev[101];
vector<int> res;
int dis[101], pre[101];
bool visited[101];
queue<int> q;
bool cycle = false;

void bellman_ford() {
	int k, i, j, start, end, cost;

	for (i = 1; i <= N; i++)
		dis[i] = INF;

	//1ºÎÅÍ N±îÁö 

	dis[1] = 0;

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			start = i;

			for (j = 0; j < p[start].size(); j++) {
				end = p[start][j].y;
				cost = p[start][j].money;

				if (dis[start] != INF && dis[end] > dis[start] + cost) {
					dis[end] = dis[start] + cost;
					pre[end] = start;

					if (k == N && visited[end])
						cycle = true;
				}
			}
		}
	}
}

int main() {

	int i, j, u, v, w, start, end, cost;

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		//+´Â È¹µæ, -´Â °¥Ãë
		scanf("%d %d %d", &u, &v, &w);
		p[u].push_back(Path(u, v, -w));
		rev[v].push_back(u);
	}

	q.push(N);

	visited[N] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (i = 0; i < rev[now].size(); i++) {
			int next = rev[now][i];

			if (!visited[next]) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}
	bellman_ford();

	if (cycle == 1)
		printf("-1");
	else {
		int tmp = N;
		while (tmp != 0) {
			res.push_back(tmp);

			tmp = pre[tmp];
		}

		for (i = res.size() - 1; i >= 0; i--)
			printf("%d ", res[i]);
	}

	return 0;
}