#include<stdio.h>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int N, L, R, res, A[201][201];
bool visited[201][201], open = false;
queue<pair<int, int> > q;
vector<pair<int, int> > v;

void Move(int x, int y) {
	v.clear();
	int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
	int sum = A[x][y], counts = 1;
	visited[x][y] = true;
	q.push(make_pair(x, y));
	v.push_back(make_pair(x, y));

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = dx[i] + now.first;
			int next_y = dy[i] + now.second;
			int minus = abs(A[now.first][now.second] - A[next_x][next_y]);
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
				continue;
			if (visited[next_x][next_y])
				continue;
			if (minus >= L && minus <= R) {
				q.push(make_pair(next_x, next_y));
				v.push_back(make_pair(next_x, next_y));
				counts++;
				sum += A[next_x][next_y];
				visited[next_x][next_y] = true;
			}
		}
	}
	if (v.size() > 1) {
		int div = sum / counts;
		//printf("sum:%d counts:%d -> div:%d \n",sum,counts,div);
		for (pair<int, int> p : v) {
			A[p.first][p.second] = div;
		}
		open = true;
	}
}

void makeFalse() {
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			visited[i][j] = false;
}

int main() {
	int i, j;
	scanf("%d %d %d", &N, &L, &R);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
	res = 0;
	while (1) {
		open = false;
		makeFalse();

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (!visited[i][j])
					Move(i, j);
			}
		}
		if (!open)
			break;
		else
			res++;

	}
	printf("%d", res);

	return 0;
}