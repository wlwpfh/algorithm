#include<stdio.h>
#include<cstdlib> //atoi 
#include<algorithm> //min, max

using namespace std;

int R, C;
int A[1501][1501], B[1501][1501], total[1501][1501];
int A_sum[1501][1501], B_sum[1501][1501];
int dp[1501][1501];
int main() {

	int i, j, tmp_number;
	char tmp[5];
	scanf("%d %d", &R, &C);

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			scanf("%s", tmp);

			if (tmp[0] == 'A')
				A[i][j] = atoi(tmp + 1);
			else
				B[i][j] = atoi(tmp + 1);
		}


	} //입력받기   

//	printf("B\n");
//	for(i=1;i<=R;i++){
//		for(j=1;j<=C;j++)
//			printf("%d ",B[i][j]);
//		printf("\n");
//	}	
//	printf("\n");

	for (j = 1; j <= C; j++) {
		for (i = R + 1; i > 1; i--)
			A_sum[i - 1][j] = A_sum[i][j] + A[i][j];
	}//사과 합 구하기  

	for (j = 2; j <= C; j++) {
		for (i = 1; i <= R; i++)
			B_sum[i + 1][j] = B_sum[i][j] + B[i][j];
	}// 바나나 합 구하기  

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			total[i][j] = A_sum[i][j] + B_sum[i][j];
			//printf("%d ",total[i][j]);	
		}
		//	printf("\n");
	} //total에 한번에 정리 

	for (i = 1; i <= R; i++)
		dp[i][0] = total[i][0];

	for (j = 1; j <= C; j++) {
		for (i = 1; i <= R; i++)
			if (i == 1)
				dp[i][j] = dp[i][j - 1] + total[i][j]; //왼쪽에서 오는 경우  
			else
				dp[i][j] = max(max(dp[i - 1][j - 1] + total[i][j], dp[i][j - 1] + total[i][j]), dp[i - 1][j] - A[i][j]);
	}



	printf("%d", dp[R][C]);

	return 0;
}