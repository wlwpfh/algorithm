#include<stdio.h>
#include<vector>

using namespace std;

int N, M, x, y, K;
int map[21][21];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 }; //동서북남  
vector<int> numbers(6); //주사위 숫자 저장 
vector<int> orders;

void rollDice(int dir) {
	if (dir == 1) { // 동
		numbers = { numbers[3], numbers[2],numbers[0], numbers[5], numbers[4], numbers[2] };
	}
	else if (dir == 2) { // 서
		numbers = { numbers[2], numbers[1],numbers[5], numbers[0], numbers[4], numbers[3] };
	}
	else if (dir == 3) { // 북
		numbers = { numbers[4], numbers[0],numbers[2], numbers[3], numbers[5], numbers[1] };
	}
	else { //dir ==4 남
		numbers = { numbers[1], numbers[5],numbers[2], numbers[3], numbers[0], numbers[4] };
	}
	return;
}

void moveDice() {
	for (int i = 0; i < K; i++) {

		int nx = dx[orders[i]] + x;
		int ny = dy[orders[i]] + y;

		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;

		y = ny;
		x = nx;

		rollDice(orders[i]);

		printf("%d \n", numbers[0]);

		if (map[x][y] == 0) {
			map[x][y] = numbers[5];
		}
		else {
			numbers[5] = map[x][y];
			map[x][y] = 0;
		}
	}
}

int main() {
	int tmp;

	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		orders.push_back(tmp);
	}

	moveDice();

	return 0;
}