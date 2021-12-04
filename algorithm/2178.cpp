#include<stdio.h>
#include<queue>
using namespace std;

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int nx, ny;
	int arr[n][m];
	int i, j;
	int answer = 0;
	int checked[n][m];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);

	queue< pair<int, int> >q;
	q.push(make_pair(0, 0));
	int x = 0, y = 0;
	while (!q.empty() && !(x == n - 1 && y == m - 1)) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx<0 || nx>m || ny<0 || ny>n) {

				continue;
			}
			if (arr[nx][ny] == 0 || checked[nx][ny] == 1) { //벽이거나 이미 갔다 온  

				continue;
			}
			else {
				checked[nx][ny] = 1;
				q.push(make_pair(nx, ny));

				printf("[%d][%d]로 이동했다 \n", nx, ny);
				answer++;
				//q.pop();
			//	break;
			}
		}
	}
	printf("answer: %d \n", answer);
	return 0;
}