#include<stdio.h>
#include<cstdlib>
#include<algorithm>

using namespace std;

int R, C;
int A[1501][1501], B[1501][1501], total[1501][1501];
int A_sum[1501][1501], B_sum[1501][1501];

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


	} //�Է¹ޱ�   

	printf("B\n");
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++)
			printf("%d ", B[i][j]);
		printf("\n");
	}
	printf("\n");

	for (j = 1; j <= C; j++) {
		for (i = R + 1; i > 1; i--)
			A_sum[i - 1][j] = A_sum[i][j] + A[i][j];
	}//��� �� ���ϱ�  

	for (j = 2; j <= C; j++) {
		for (i = 1; i <= R; i++)
			B_sum[i + 1][j] = B_sum[i][j] + B[i][j];
	}// �ٳ��� �� ���ϱ�  

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			total[i][j] = A_sum[i][j] + B_sum[i][j];
			//printf("%d ",total[i][j]);	
		}
		//	printf("\n");
	} //total�� �ѹ��� ���� 

	for (j = 1; j <= C; j++) {
		for (i = 1; i <= R; i++) {

		}
	}



	return 0;
}