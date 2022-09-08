#include<stdio.h>

using namespace std;

int N, answer = 0;
int map[16][16];
int dx[] = { 0,1,1 }; //���� ���� �밢��  
int dy[] = { 1,0,1 };
//ó�� �κ��� �ƴ϶� ������ �κи� ���� ���� �ȴ� .  

void move(int now_x, int now_y, int dir) {
	if (now_x == N - 1 && now_y == N - 1) {
		answer++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nx = dx[i] + now_x;
		int ny = dy[i] + now_y;

		if (dir == 0 && i == 1 || dir == 1 && i == 0)
			continue;

		if (nx<0 || nx>N || ny<0 || ny>N)
			continue;

		if (map[nx][ny] == 1)
			continue;

		if (i == 2 && (map[now_x + 1][now_y] == 1 || map[now_x][now_y + 1] == 1))
			continue;
		move(nx, ny, i);
	}

}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	//0�� �� ĭ�̰� 1�� �� 

	move(0, 1, 0);

	printf("%d", answer);

	return 0;
}