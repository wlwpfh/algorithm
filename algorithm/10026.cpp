#include<queue>
#include<iostream>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char c[101][101];
int checked[101][101];
int color[101][101];
int redgreen[101][101];
int main() {
	int n;
	scanf("%d", &n);

	int i, j;

	int answer = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> c[i][j];

		}
	}
	queue<pair<int, int> >q;
	//	for(i=0;i<n;i++){
	//		for(j=0;j<n;j++){
	//			printf("%c ",c[i][j]);
	//		}
	//		printf("\n");
	//	} //잘 들어감. 

	q.push(make_pair(0, 0));

	checked[0][0] = 1;
	int x, y;
	char tmp = c[0][0];
	color[0][0] = 1;
	redgreen[0][0] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (checked[nx][ny] == 1)
				continue;
			if (c[x][y] != c[nx][ny] && color[nx][ny] == 0) {
				//checked[nx][ny]=1;
				//tmp=c[nx][ny];
				color[nx][ny] = color[x][y] + 1;
				//q.push(make_pair(nx,ny));

			}
			else if (c[x][y] == c[nx][ny] && color[nx][ny] == 0) {
				color[nx][ny] = color[x][y];
				//checked[nx][ny]=1;
			}
			if ((c[x][y] == 'R' && c[nx][ny] == 'G') || (c[x][y] == 'G' && c[nx][ny] == 'R') || c[x][y] == c[nx][ny]) { //적록색약  
				redgreen[nx][ny] = redgreen[x][y];
			}
			else {
				redgreen[nx][ny] = redgreen[x][y] + 1;
			}
			checked[nx][ny] = 1;
			q.push(make_pair(nx, ny));
		}

	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", color[i][j]);
		printf("\n");
	}
	printf("\n \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", redgreen[i][j]);
		printf("\n");
	}
	printf("%d \n", color[n - 1][n - 1]);
	printf("%d \n", redgreen[n - 1][n - 1]);
	//	printf("%d",answer);
	return 0;
}