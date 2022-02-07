#include<stdio.h>

using namespace std;

int main() {

	int N, M;

	int i, j;
	scanf("%d %d", &N, &M);
	int c1 = N * M, c2 = N * M, answer = 0, tmp = 0;
	char arr[N][M];
	//nt tmp[N][M]={0,};
	for (i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
	}

	//0~ N-8이 시작 
	int start_i;
	int start_j;

	for (start_i = 0; start_i <= N - 8; start_i++) {
		for (start_j = 0; start_j <= M - 8; start_j++) {
			for (i = start_i; i < N; i++) {
				for (j = start_j; j < M; j++) {
					if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
						//W가 잇어야 함. 
						if (arr[i][j] != 'W')
							tmp++;
					}
					else {
						if (arr[i][j] != 'B')
							tmp++;
					}
				}

			}
			c1 = c1 > tmp ? tmp : c1;
			tmp = 0;
		}
	}

	tmp = 0;
	printf("W로 시작했을 때 다시 칠해야하는 것의 수는 %d \n", c1);

	for (start_i = 0; start_i <= N - 8; start_i++) {
		for (start_j = 0; start_j <= M - 8; start_j++) {
			for (i = start_i; i < N; i++) {
				for (j = start_j; j < M; j++) {
					if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
						//W가 잇어야 함. 
						if (arr[i][j] != 'B')
							tmp++;
					}
					else {
						if (arr[i][j] != 'W')
							tmp++;
					}
				}

			}
			c2 = c2 > tmp ? tmp : c2;
			tmp = 0;
		}
	}

	printf("B로 시작했을 때 다시 칠해야하는 것의 수는 %d \n", c2);

	answer = c1 < c2 ? c1 : c2;
	printf("%d", answer);
	return 0;
}

//아 정사각형의 최솟값임..  