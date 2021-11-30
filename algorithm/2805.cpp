#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int n, i, j;
	cin >> T;
	int sum;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		sum = 0;
		scanf("%d", &n);

		int arr[n][n];

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				scanf("%1d", &arr[i][j]);
		}

		//printf("%d", 5/2);

		for (i = 0; i <= n / 2; i++) {
			for (j = n / 2 - i; j <= n / 2 + i; j++) {
				//printf("arr[%d][%d]=%d ",i,j,arr[i][j]);
				//sum+=arr[i][j];
			}
			printf("\n");
		}

		for (i = n / 2 + 1; i < n; i++) {
			for (j = n / 2 - i / 2; j <= n / 2 + i / 2; j++) {
				printf("arr[%d][%d]=%d ", i, j, arr[i][j]);
				//sum+=arr[i][j];
			}
			printf("\n");
		}


		printf("#%d %d \n", test_case, sum);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.n
}