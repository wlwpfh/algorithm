#include<stdio.h>
#include<queue>
#include<vector>
#define MAX_N 200 
using namespace std;

queue<pair<int, int> > q;
int map[MAX_N + 1][MAX_N + 1] = { 0, };
int checked[MAX_N + 1][MAX_N + 1] = { 0, };
int N, K, S, X, Y;
//N * N ���, �� K���� ���̷���, S�� ���� X,Y�� �ִ� ���̷��� ���� ��� 
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//�� ��ġ���� �ʸ��� �̵��� ����... �� ��ġ�� ��� ���۵Ǵ��� �� ����Ʈ�� ��� �ϴ°� �ƴѰ�? 
//�ʸ��� �ֱ� ��ġ�� �ֱ�?  

struct Start {
	int x;
	int y;
	Start(int a, int b) {
		x = a;
		y = b;
	}
};

vector<Start> point;

void bfs(int x, int y) {
	q.push(make_pair(x, y));
	checked[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) //������ ��� ��� 
				continue;
			if (checked[nx][ny] == 0) {
				checked[nx][ny] = 1;
				map[nx][ny] = map[x][y];
				q.push(make_pair(nx, ny));
			}
			if (map[nx][ny] > map[x][y]) {
				map[nx][ny] = map[x][y];
			}

		}
	}
}

int main() {
	int i, j, count = 0;
	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

		if (map[i][j] != 0)
			point.push_back(Start(i, j));
	}

	scanf("%d %d %d", &S, &X, &Y);

	//	for(i=0;i<N;i++){
	//		for(j=0;j<N;j++){
	//			if(checked[i][j]==0 && map[i][j]!=0){
	//				bfs(i,j);
	//				count++;
	//			}
	//			if(count==S)
	//				break;			
	//		
	//		}
	//		if(count==S)
	//			break;
	//				
	//	}

	for (count = 0; count <= S; count++) {
		for (i = 0; i < point.length(); i++) {

		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	printf("%d", map[X][Y]);


}