#include<stdio.h>
#include<queue>
#define INF 987654321
using namespace std;

int N, M;
int map[1000][1000];
queue<pair<int, int > > q;
queue<pair<int, int> >wall;
int move;
bool meet_end;

void Move() {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	int move = 0;

	q.push(make_pair(0, 0));
	map[0][0] = 1;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + p.first;
			int ny = dy[i] + p.second;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (map[nx][ny] == 0) {
				map[nx][ny] = map[p.first][p.second] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void fill_zero() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (map[i][j] != -1)
				map[i][j] = 0;
	}
}

int main() {
	int i, j, min;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);

			if (map[i][j] == 1) {
				wall.push(make_pair(i, j));
				map[i][j] = -1;
			}
		}


	min = INF;

	while (!wall.empty()) {
		pair<int, int> now = wall.front();
		wall.pop();

		map[now.first][now.second] = 0;
		Move();

		meet_end = map[N - 1][M - 1] != 0 ? true : false;

		if (meet_end == true)
			min = min > map[N - 1][M - 1] ? map[N - 1][M - 1] : min;

		map[now.first][now.second] = -1;
		fill_zero();
	}

	if (min != INF)
		printf("%d", min);
	else
		printf("-1");
	return 0;
}