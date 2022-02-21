#include<stdio.h>
#include<algorithm>
using namespace std;

int N, A[101];
bool number[101];
int cal[4];
//µ¡¼À, »¬¼À, °ö¼À, ³ª´°¼À
int cal_count = 0;
int min_value = 987654321, max_value = -987654321, tmp;

void calculate(int number_count, int sum) {
	printf("ÇöÀç ¼ýÀÚ: %d, ÇöÀçÀÇ ÃÑ ÇÕ: %d \n", A[number_count], sum);
	if (number_count == N) {
		min_value = min(min_value, sum);
		max_value = max(max_value, sum);
	}
	else {
		if (cal[0] > 0) {
			cal[0]--;
			calculate(number_count + 1, sum + A[number_count + 1]);
			cal[0]++;
		}
		if (cal[1] > 0) {
			cal[1]--;
			calculate(number_count + 1, sum - A[number_count + 1]);
			cal[1]++;
		}
		if (cal[2] > 0) {
			cal[2]--;
			calculate(number_count + 1, sum * A[number_count + 1]);
			cal[2]++;
		}
		if (cal[3] > 0) {
			cal[3]--;
			calculate(number_count + 1, sum / A[number_count + 1]);
			cal[3]++;
		}
	}
}

int main() {
	int i;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	for (i = 0; i < 4; i++) {
		scanf("%d", &cal[i]);
	}


	calculate(1, A[1]);

	printf("%d \n%d", max_value, min_value);


	return 0;
}