#include<queue>
#include<iostream>
#include<cstring>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char c[101][101];
int checked[101][101];
queue<pair<int, int> >q;

int n;

void bfs(int x, int y, bool redgreen) {

	q.push(make_pair(x, y));
	checked[x][y] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;


			if (redgreen == true) {
				if ((c[cx][cy] == 'R' || c[cx][cy] == 'G') && (c[nx][ny] == 'R' || c[nx][ny] == 'G') || c[nx][ny] == c[x][y]) {
					if (checked[nx][ny] == 0) {
						checked[nx][ny] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
			else {
				if (checked[nx][ny] == 0 && c[nx][ny] == c[x][y]) {
					checked[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}




		}
	}

}


int main() {

	scanf("%d", &n);

	int i, j;
	int a = 0, b = 0;
	int answer = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> c[i][j];

		}
	}
	memset(checked, 0, sizeof(checked));

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (checked[i][j] == 0) {

				bfs(i, j, false);
				a++;
			}
		}
	}

	memset(checked, 0, sizeof(checked));

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (checked[i][j] == 0) {

				bfs(i, j, true);
				b++;
			}
		}
	}

	printf("%d %d", a, b);


	return 0;

}