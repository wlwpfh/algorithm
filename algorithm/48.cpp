#include<stdio.h>
#include<math.h>
int main() {
	int arr[9][9];
	int avg[9][2];
	int i, j, sum = 0;

	int tmp_close = -20000;
	int tmp = 0;
	for (i = 0; i < 9; i++) {

		for (j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			sum = sum + arr[i][j];
		}
		avg[i][0] = round(sum / 9.0);

		sum = 0;
	}

	printf("\n");
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (abs(arr[i][j] - avg[i][0]) <= abs(tmp_close - avg[i][0])) {



				if (abs(arr[i][j] - avg[i][0]) == abs(tmp_close - avg[i][0])) {
					if (arr[i][j] < tmp_close) {
						tmp = tmp_close;

					}
					else { //더 큰 경우 
						tmp = arr[i][j];
						tmp_close = tmp;
					}
				}
				else {

					tmp_close = arr[i][j];
					tmp = arr[i][j];
				}
			}
		}
		avg[i][1] = tmp;
		tmp_close = 0, tmp = 0;
		printf("%d %d \n", avg[i][0], avg[i][1]);
	}

	return 0;
}