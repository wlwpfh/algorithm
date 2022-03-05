#include<stdio.h>

using namespace std;

char arr[3100][6200] = { ' ', };

void printStars(int x, int y) {
	arr[x][y] = '*';
	arr[x + 1][y - 1] = '*';
	arr[x + 1][y + 1] = '*';

	for (int i = y - 2; i <= y + 2; i++)
		arr[x + 2][i] = '*';
}


void star(int i, int j, int num) { //x 
	if (num == 3) {
		printStars(i, j);
		//가장 작은 삼각형 그리기  
		return;
	}
	//꼭짓점 이동 
	star(i, j, num / 2);
	star(i + num / 2, j - num / 2, num / 2);
	star(i + num / 2, j + num / 2, num / 2);



}

int main() {

	int num, i, j;

	scanf("%d", &num);


	star(0, num - 1, num);

	for (i = 0; i < num; i++) {
		for (j = 0; j < 2 * num; j++) {
			if (arr[i][j] == '*')
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}


	return 0;
}