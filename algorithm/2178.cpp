#include<stdio.h>
#include<queue>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int arr[n][m];
	int answer[n][m] = { 0, };
	int i, j;
	int checked[n][m];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);


	queue< pair<int, int> >q;
	q.push(make_pair(0, 0));
	checked[0][0] = 1;
	int x = 0, y = 0;
	answer[0][0] = 1;
	while (!q.empty()) {

		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (arr[nx][ny] == 0 || checked[nx][ny] == 1) { //벽이거나 이미 갔다 온  
				;
			}
			else {
				answer[nx][ny] = answer[x][y] + 1;
				checked[nx][ny] = 1;

				q.push(make_pair(nx, ny));
			}
		}
	}

	printf("%d", answer[n - 1][m - 1]);
	return 0;
}