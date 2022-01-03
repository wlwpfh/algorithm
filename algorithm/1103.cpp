#include<stdio.h>

using namespace std;

int n, m;
int dp[55][55] = { 0, }; //중복 계산을 막기 위해 계산 결과 저장  
char map[55][55] = { 0, };
bool visited[55][55];
int max_level = 0;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void go(int x, int y, int level) {

	dp[x][y] = level;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * (map[x][y]);
		int ny = y + dy[i] * (map[x][y]);

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 'H') {
			if (level > max_level) max_level = level; //끝난 경우  
			return;
		}


		if (dp[nx][ny] > 0 || visited[nx][ny] == true) {
			max_level = -1;
			return;
		}


		dp[nx][ny] = level + 1;
		visited[nx][ny] = true;
		go(nx, ny, level + 1);

	}
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	go(0, 0, 0);

	printf("%d", max_level);
	return 0;
}