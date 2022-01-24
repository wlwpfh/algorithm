#include<stdio.h>

using namespace std;

int main() {

	int N, M;
	int c1 = 0, c2 = 0;
	int i, j;
	scanf("%d %d", &N, &M);

	char arr[N][M];

	for (i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
				//W가 잇어야 함. 
				if (arr[i][j] != 'W')
					c1++;
			}
			else {
				if (arr[i][j] != 'B')
					c1++;
			}
		}

	}
	printf("W로 시작했을 때 다시 칠해야하는 것의 수는 %d \n", c1);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
				if (arr[i][j] != 'B')
					c2++;
			}
			else {
				if (arr[i][j] != 'W')
					c2++;
			}
		}

	}
	printf("B로 시작했을 때 다시 칠해야하는 것의 수는 %d \n", c2);

	printf("%d", c1 < c2 ? c1 : c2);

	return 0;
}

//아 정사각형의 최솟값임..  