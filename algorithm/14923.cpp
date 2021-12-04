#include<stdio.h>
#include<queue>
using namespace std;

int main() {

	int n, m;
	int hx, hy;
	int ex, ey;

	queue<pair<int, int> > q;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int nx, ny;
	//1이 벽 , 0이 길 
	int i, j;
	int answer = 0;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &hx, &hy);
	scanf("%d %d", &ex, &ey);
	int miro[n][m];
	int checked[n][m] = { 0, };
	pair<int, int> tmp;

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", miro[i][j]);

	tmp = make_pair(hx, hy);

	q.push(tmp);
	checked[hx][hy] = 1;

	while (!q.empty()) {
		for (i = 0; i < 4; i++) {
			nx = hx + dx[i];
			ny = hy + dy[i];

			if (nx<0 || ny<0 || nx>n || ny>m)
				continue;
			if (checked[nx][ny] == 1)
				continue;

			if (checked[nx][ny] == 0 && miro[nx][ny] == 0) {
				checked[nx][ny] = 1;
				tmp = make_pair(nx, ny);
				q.push(tmp);
				q.pop();
				answer++;
			}
		}
	}
	printf("answer: %d \n", answer);
	return 0;
}