#include<stdio.h>

int maze[8][8], count = 0;

void findingPath(int i, int j) {
	if (i == 7 && j == 7) {
		count++;
		return;
	}
	if (maze[i][j] == 0) { //���� ��� 
		findingPath(i, j++);
		findingPath(i++, j);

	}
	else { //1�� ��� �Դ� �� �ǵ��ư��� 

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