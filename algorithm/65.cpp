#include<stdio.h>

int maze[8][8], check[8][8], count = 0;

void findingPath(int i, int j) {
	if (i == 7 && j == 7) {
		count++;
	}
	if (maze[i][j] == 0 && check[i][j] == 0) { //답인 경우 
		check[i][j++] = 1;
		findingPath(i, j);
		check[i][j] = 0;
		check[i++][j] = 1;
		findingPath(i, j);
		check[i][j] = 0;
	}
}

int main() {
	int i, j;

	for (i = 1; i <= 7; i++) {
		for (j = 1; j <= 7; j++) {
			scanf("%d", &maze[i][j]);
		}
	}

	findingPath(1, 1);

	printf("%d", count);

	return 0;
}
