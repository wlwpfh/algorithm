#include<queue>
#include<iostream>
#include<cstring>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char c[101][101];
int checked[101][101];


int n;
int i;
void bfs(int x, int y, bool redgreen) {
	queue<pair<int, int> >q;
	q.push(make_pair(x, y));
	checked[x][y] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (checked[nx][ny] == 1)
				continue;
			if (redgreen == true) {
				if (c[cx][cy] == 'R' || c[cx][cy] == 'G') {
					if (c[nx][ny] == 'G' || c[nx][ny] == 'R') {
						q.push(make_pair(nx, ny));
						checked[nx][ny] = 1;
					}
				}
			}
			else {
				if (c[cx][cy] == c[nx][ny]) {
					q.push(make_pair(nx, ny));
					checked[nx][ny] = 1;

				}
			}

		}
	}

}


int main() {
	int n;
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

	printf("%d \n", a);
	printf("%d \n", b);

	return 0;

}