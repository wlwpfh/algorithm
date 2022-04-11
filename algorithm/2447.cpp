#include<stdio.h>

using namespace std;

int N;

void makeStar(int n, int i, int j) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		printf(" ");
	//해당 n안에서 딱 가로세로의 중간에 있는 빈칸이어야 하니까  
	else if (n / 3 == 0)
		printf("*");
	//n이 3으로 끝나고 위의 경우가 아닐 때 	
	else
		makeStar(n / 3, i, j);
	//n을 쪼개가면서 위의 값들이 될 때까지  
}

int main() {

	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			makeStar(N, i, j);
		printf("\n");
	}


	return 0;
}