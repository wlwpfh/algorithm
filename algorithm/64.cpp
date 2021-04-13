#include<stdio.h>

int n, m, count = 0, graph[21][21];

void path_finding(int i, int j) {
	if (j == 5) { //끝내야함 
		count++;
	}
	if (graph[i][j] == 1) {
		path_finding(j, i);
	}
	else { //0인 경우 다른 길을 찾아야 함 
		if (i != j) //자기 자신 값이 0이니까	 
		{

			path_finding(i, j++);
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

	path_finding(1, 1);

	printf("%d", count);

	return 0;
}