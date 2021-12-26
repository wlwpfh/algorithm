#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;

int m, n;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int checked[51][51];
int baechu[51][51];
queue< pair<int, int> >q;
void findWorms(int a, int b) {
	checked[a][b] = 1;
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || ny>n || nx<0 || nx>m)
				continue;


			if (baechu[ny][nx] == 1 && checked[ny][nx] == 0) {
				q.push(make_pair(ny, nx));
				checked[ny][nx] = 1;
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
		memset(checked, 0, sizeof(checked));
		scanf("%d %d %d", &m, &n, &k);
		//가로 세로 지렁이개수  

		for (a = 0; a < k; a++) {
			scanf("%d %d", &tmp1, &tmp2);
			//가로 세로  
			baechu[tmp2][tmp1] = 1;

		}
		for (a = 0; a < n; a++) {
			for (b = 0; b < m; b++) {
				printf("%d ", baechu[a][b]);
			}
			printf("\n");
		}

		for (a = 0; a < n; a++) {
			for (b = 0; b < m; b++) {
				if (checked[a][b] == 0 && baechu[a][b] == 1) {
					findWorms(a, b);
					// 1차원 2차원  
					worms[c]++;
				}
			}
		}


		printf("%d \n", worms[c]);
	}


	return 0;
}