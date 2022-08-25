#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct Wall {
	int x, y, crushed;
};

int N, M, answer = -1;
char map[1000][1000];
int dis[1000][1000][2] = { 0, };
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

int Move() {
	queue<Wall> q;
	dis[0][0][0] = 1;
	q.push({ 0,0,0 });

	while (!q.empty()) {

		Wall now = q.front();
		int x = now.x, y = now.y, crush = now.crushed;

		q.pop();

		if (x == N - 1 && y == M - 1) {

			return dis[now.x][now.y][now.crushed];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) //범위 밖  
				continue;

			if (map[nx][ny] == '1' && crush == 0) { //벽이고 벽을 부순 적이 없다면  
				q.push({ nx,ny,crush + 1 }); //한번 부숨  
				dis[nx][ny][crush + 1] = dis[x][y][crush] + 1;
			}
			else if (map[nx][ny] == '0' && dis[nx][ny][crush] == 0) { //가본적이 없는곳

				q.push({ nx,ny,crush });
				dis[nx][ny][crush] = dis[x][y][crush] + 1;
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < M; j++)
			map[i][j] = s[j];

	}



	cout << Move() << endl;

	return 0;
}