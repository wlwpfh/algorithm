#include<stdio.h>
#include<queue>

using namespace std;

int N, M, ans = 0;
int map[8][8], dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int tmp[8][8];
queue<pair<int, int> >q;

//void print(){
//	int i,j;
//	for(i=0;i<N;i++){
//		for(j=0;j<M;j++){
//			printf("%d ",map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

void findZero() {
	int i, j, count = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (tmp[i][j] == 0)
				count++;
		}
	}
	ans = ans > count ? ans : count;

}
void setTwo() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) {
				q.push(make_pair(i, j));
			}
			tmp[i][j] = map[i][j];
		}
	}
}

void searchMap() {
	int i, j, virus = 0;

	//map을 다시 초기화하기  
	setTwo();

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (i = 0; i < 4; i++) {
			int next_x = now.first + dx[i];
			int next_y = now.second + dy[i];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
				continue;

			if (tmp[next_x][next_y] == 0) {
				tmp[next_x][next_y] = 2;
				q.push(make_pair(next_x, next_y));
			}
		}
	}

	findZero();

	return;
}

void makeWall(int x, int y, int count) {
	if (count == 3) {

		searchMap();
		return;
	}
	for (int i = x; i < N; i++) {
		for (int j = y; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;

				makeWall(i, j + 1, count + 1);

				map[i][j] = 0;
			}
		}
		y = 0;
	}
}

int main() {
	int i, j;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	makeWall(0, 0, 0);

	printf("%d", ans);

	return 0;
}