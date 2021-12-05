
#include<queue>
#include<iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int i, j;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	char c[101][101];
	int checked[101][101];
	//int answer[101][101];
	//같은 것이라고 판단되면 answer++;
	int answer = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}
	queue<pair<int, int> >q; //좌표  
	//int checked[101][101];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%c ", c[i][j]);
		}
		printf("\n");
	} //잘 들어감. 

	q.push(make_pair(0, 0));
	//answer[0][0]=1;
	checked[0][0] = 1;
	int x, y;
	char tmp = c[0][0];
	answer = 1;
	while (!q.empty()) {
		//if(c[i][j]가 뭐면 ㄱㅊ
		//사방이 다 다르면 ++; 
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (tmp != c[nx][ny] && checked[nx][ny] == 0) {
				checked[nx][ny] = 1;
				answer++;
				tmp = c[nx][ny];
			}
		}

	}
	printf("%d", answer);
	return 0;
}