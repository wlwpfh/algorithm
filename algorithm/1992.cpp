#include<stdio.h>

using namespace std;

int arr[65][65];

void recursive(int x, int y, int number) {
	//시작 점
	int point = arr[x][y];
	for (int i = x; i < x + number; i++) {
		for (int j = y; j < y + number; j++) {
			if (point != arr[i][j]) {
				point = -1;
				break;
			}//시작점과 다른 수가 있음  
		}
		if (point == -1)
			break;
	}

	if (point == -1) {
		//다른 수가 있는 거니까 
		printf("(");
		recursive(x, y, number / 2); //왼쪽 위  
		recursive(x, y + number / 2, number / 2); //오른쪽 위  
		recursive(x + number / 2, y, number / 2); //왼쪽  아래  
		recursive(x + number / 2, y + number / 2, number / 2); // 오른쪽 아래  
		printf(")");
	}
	else if (point == 1) {
		printf("1"); //다 1인 거니까  
	}
	else if (point == 0)
		printf("0");

}

int main() {

	int N, i, j;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			scanf("%1d", &arr[i][j]);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	recursive(1, 1, N);

	return 0;
}