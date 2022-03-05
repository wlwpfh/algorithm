#include<stdio.h>

using namespace std;

char arr[3073][6145] = { ' ', };

void printStars(int x, int y) {
	arr[x][y] = '*';
	arr[x - 1][y + 1] = '*';
	arr[x + 1][y + 1] = '*';

	//	for(int i=x-2; i<=x+2;i++)
	//		arr[i][y+2]='*';	
}


void star(int i, int j, int num) { //xÁÂÇ¥, yÁÂÇ¥  
	if (num == 3) {
		printStars(i, j);
		//°¡Àå ÀÛÀº »ï°¢Çü ±×¸®±â  
		return;
	}
	else {
		//²ÀÁþÁ¡ ÀÌµ¿ 
		star(i, j, num / 2);
		star(i + num / 2, j - num / 2, num / 2);
		star(i + num / 2, j + num / 2, num / 2);

	}


}

int main() {

	int num, i, j;

	scanf("%d", &num);


	star(num, 0, num);

	for (i = 0; i <= num; i++) {
		for (j = 0; j <= 2 * num; j++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}


	return 0;
}