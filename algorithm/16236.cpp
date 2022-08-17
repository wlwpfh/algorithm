#include<stdio.h>
#include<queue>

using namespace std;

typedef pair<int, int> pii;
queue <pii> q;
int N, map[20][20], shark_size = 2, dis = 0;
//0:빈칸,  123456:물고기 크기, 9:아기상어 위치  
bool visited[20][20];
void BFS() {
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };

		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny])
				continue;
			if (map[nx][ny] > shark_size)
				continue;

			if (map[nx][ny] < shark_size) {
				shark_size += map[nx][ny];
				map[nx][ny] = 0;
			}
			//같거나 작은 경우에 
			visited[nx][ny] = true;
			dis++;
			q.push(make_pair(nx, ny));
		}
	}
}

int main() {
	int i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 9) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}

	BFS();

	printf("size:%d distance:%d \n", shark_size, dis);

	return 0;
}