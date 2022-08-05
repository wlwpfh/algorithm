#include<stdio.h>
#include<queue>

using namespace std;

int M, N, count;
int tomato[1000][1000];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sum;

struct Tomato {
	int x; int y;

	Tomato(int a, int b) {
		x = a; y = b;
	}
};
//0은 익지 않음, -1 토마토가 들어있지 않음. 1은 익은 토마토  
queue<Tomato> q;

void Cook() {
	while (!q.empty()) {

		Tomato t = q.front();
		q.pop();
		count++;
		sum = 0;
		for (int i = 0; i < 4; i++) {
			int new_x = t.x + dx[i];
			int new_y = t.y + dy[i];



			if (new_y < 0 || new_y >= M || new_x < 0 || new_x >= N)
				continue;
			if (tomato[new_x][new_y] == 0) {
				q.push(Tomato(new_x, new_y));
				tomato[new_x][new_y] = 1;
				sum++;
			}

		}
		if (sum == 0)
			count--;
		printf("count:%d \n", count);

	}
}

int main() {

	int i, j;

	scanf("%d %d", &M, &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1) {
				q.push(Tomato(i, j));
			}
		}
	}


	Cook();

	printf("\n");


	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (tomato[i][j] == 0) {
				printf("0");
				return 0;
			}

	return 0;
}