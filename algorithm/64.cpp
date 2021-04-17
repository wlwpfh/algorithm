#include<stdio.h>

int n, m, count = 0, graph[21][21], path[21];

void path_finding(int dest) { //도착 지점 
	int i;
	if (dest == n) { //끝내야함 
		count++;
	}
	else {
		for (i = 1; i <= m; i++) {
			if (graph[dest][i] == 1 && path[i] == 0) {
				path[i] = 1;
				path_finding(i);
				path[i] = 0;
			}
		}
	}



}
int main() {
	int i, j, a, b;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;

	}

	path[1] = 1;


	path_finding(1);

	printf("%d", count);

	return 0;
}