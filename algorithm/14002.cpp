#include<stdio.h>

using namespace std;

int A[1001];
int DP[1001];
int pre[1001];

void printAns(int num) {
	if (num == 0)
		return;

	printAns(pre[num]);
	printf("%d ", A[num]);

}

int main() {

	int N, i, j, index, count = 0;

	scanf("%d", &N);


	for (i = 1; i <= N; i++)
		scanf("%d", &A[i]);


	for (i = 1; i <= N; i++) {

		DP[i] = 1;
		pre[i] = 0;

		for (j = 1; j < i; j++) {
			if (A[i] > A[j]) {
				if (DP[i] < DP[j] + 1) {
					DP[i] = DP[j] + 1;
					pre[i] = j;
					//printf("value= %d \n",value);	
				}
			}

		}

		if (count < DP[i]) {
			index = i; //마지막 index위치  
			count = DP[i]; // LIS의 제일 큰 값  
		}

	}



	printf("%d \n", count);
	printAns(index);


	return 0;
}