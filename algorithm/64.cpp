#include<stdio.h>

int n, m, count = 0, graph[21][21];

void path_finding(int i, int j) {
	if (j == 5) { //�������� 
		count++;
	}
	if (graph[i][j] == 1) {
		path_finding(j, i);
	}
	else { //0�� ��� �ٸ� ���� ã�ƾ� �� 
		if (i != j) //�ڱ� �ڽ� ���� 0�̴ϱ�	 
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