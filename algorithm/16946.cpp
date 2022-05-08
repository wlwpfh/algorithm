#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int map[1001][1001]; //�� ����  
bool visited[1001][1001]; //�ߺ� Ȯ�ο�  
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 }; //�� �̵���  
int N, M;

void BFS(int a, int b) {
	int i, count = 1;
	queue<pair<int, int> >q;
	vector<pair<int, int> > wall;

	q.push(make_pair(a, b));
	visited[a][b] = true;

	while (!q.empty()) {
		pair<int, int> tmp_p = q.front();
		int x = tmp_p.first;
		int y = tmp_p.second;

		q.pop();


		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (map[nx][ny] == 0 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				count++;
			}//��� ���� ���  
			else if (map[nx][ny] != 0 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				wall.push_back(make_pair(nx, ny));
				//������ ���� �� �ֱ�  
			}//���� �μ� ���  
		}
	}
	for (i = 0; i < wall.size(); i++) {//���� ���鿡 ���� ���ϱ�  
		map[wall[i].first][wall[i].second] += count;
		visited[wall[i].first][wall[i].second] = false;

		//printf("map[%d][%d]= %d \n",wall[i].first, wall[i].second, map[wall[i].first][wall[i].second]);
	}


}
int main() {

	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	// 0�� ��, 1�� ��

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			if (map[i][j] == 0 && visited[i][j] == false)
				BFS(i, j);
		// ���� ���� ���� ��  
	}
	printf("\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			printf("%d", map[i][j] % 10);
		printf("\n");
	}



	return 0;
}