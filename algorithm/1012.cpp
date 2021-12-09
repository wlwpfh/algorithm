#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;

int m, n;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int checked[50][50];
int baechu[50][50];
queue< pair<int, int> >q;
void findWorms(int x, int y) {
	checked[x][y] = 1;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<0 || nx>m || ny<0 || ny>n)
				continue;
			if (checked[nx][ny] == 1) continue;

			if (baechu[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				checked[nx][ny] = 1;
			}
		}

	}
}

int main() {
	int a, b, c;
	int t, k, x, y;
	int tmp1, tmp2;
	scanf("%d", &t);
	int worms[t] = { 0, };
	for (c = 0; c < t; c++) {
		memset(baechu, 0, sizeof(baechu));
		scanf("%d %d %d", &m, &n, &k);


		for (a = 0; a < k; a++) {
			scanf("%d %d", &tmp1, &tmp2);
			baechu[tmp1][tmp2] = 1;

		}


		for (a = 0; a < m; a++) {
			for (b = 0; b < n; b++) {
				if (checked[a][b] == 0 && baechu[a][b] == 1) {
					findWorms(a, b);
					worms[c]++;
				}
			}
		}

		//printf("%d \n",worms[c]);	
	}

	for (c = 0; c < t; c++) {
		printf("%d \n", worms[c]);
	}

	return 0;
}