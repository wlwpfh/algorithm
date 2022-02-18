#include<stdio.h>
#include<queue>
#include<vector>
#define MAX_N 200 
using namespace std;

queue<pair<int, int> > q;
int map[MAX_N + 1][MAX_N + 1] = { 0, };
int checked[MAX_N + 1][MAX_N + 1] = { 0, };
int visited[MAX_N + 1][MAX_N + 1] = { 0, };
int N, K, S, X, Y;
//N * N 행렬, 총 K개의 바이러스, S초 후의 X,Y에 있는 바이러스 종류 출력 
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//각 위치에서 초마다 이동행 ㅑ함... 각 위치가 어디서 시작되는지 그 포인트를 줘야 하는거 아닌가? 
//초마다 최근 위치를 주기?  

struct Start {
	int x;
	int y;
	int virus;
	Start(int a, int b, int c) {
		x = a;
		y = b;
		virus = c;
	}
	bool operator<(Start s) {
		return virus < s.virus;
	}
};

vector<Start> point;

void bfs(int a, int b) {
	q.push(make_pair(a, b)); //위치를 받음  
	checked[a][b] = 1;
	visited[a][b] = 1;
	int j;
	int virus = map[a][b];
	int x = q.front().first;
	int y = q.front().second;
	q.pop();
	printf("현재 바이러스의 위치: (%d, %d) \n", x, y);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//printf("nx: %d, ny: %d \n",nx,ny);
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) //범위를 벗어난 경우 
			continue;
		if (map[nx][ny] == 0) {
			checked[nx][ny] = 1;
			map[nx][ny] = map[x][y];
			//printf("(%d, %d)에도 바이러스(%d)전염 \n",nx,ny,virus); 
		}
		else if (map[nx][ny] > map[x][y] && checked[nx][ny] == 1) {
			//printf("(%d, %d)에 바이러스(%d) -> 바이러스(%d) 전염 \n",nx,ny,map[nx][ny],virus); 	 
			map[nx][ny] = map[x][y];

		}

	}

	for (int i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return;
	//return virus;
}

int main() {
	int i, j, count = 0;
	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

		if (map[i][j] != 0)
			visited[i][j] = 1;
		//point.push_back(Start(i,j,map[i][j]));
	}

	scanf("%d %d %d", &S, &X, &Y);


	for (int k = 0; k < S; k++) {
		printf("%d초 |||||||| \n", k + 1);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {

				if (checked[i][j] == 0 && map[i][j] != 0) {
					printf("%d번 바이러스 %d로 감염 시작 !!!!\n", count + 1, map[i][j]);
					bfs(i, j);
					count++;


				}

			}


		}
	}




	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	printf("%d", map[X][Y]);


	return 0;
}