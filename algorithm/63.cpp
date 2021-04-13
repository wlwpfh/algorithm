#include<stdio.h>

int adj[21][21];
int info[21][3];

int main63() {
	int i, j, n, m;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &info[i][0], &info[i][1], &info[i][2]);


		adj[info[i][0]][info[i][1]] = info[i][2];

	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}

	return 0;
}