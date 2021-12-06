#include<stdio.h>
#include<queue>

using namespace std;

int n, m;
int arr[1001][1001];
int checked[1001];
queue<int> q;

void bfs(int start) {
	checked[start] = 1;
	q.push(start);
	printf("%d ", start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[x][i] == 1 && checked[i] == 0) {
				checked[i] = 1;
				q.push(i);
				printf("%d ", i);
			}
		}
	}
}
void dfs(int start) {
	checked[start] = 1;
	printf("%d ", start);
	for (int i = 1; i <= n; i++) {
		if (arr[start][i] == 1 && checked[i] == 0)
			dfs(i);
	}
}
int main() {
	int x;
	int s;
	int i;
	int a = 0;
	int b;
	scanf("%d %d %d", &n, &m, &s);

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(s);

	for (i = 1; i <= n; i++)
		checked[i] = 0;
	printf("\n");
	bfs(s);



	return 0;
}