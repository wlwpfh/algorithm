#include<stdio.h>

using namespace std;

int T, K;
int p[102];
int n[102];
int DP[10005];

int main() {
	int i, j, l;

	scanf("%d", &T); //�ݾ� 
	scanf("%d", &K); //������ ���� ��  

	for (i = 0; i < K; i++)
		scanf("%d %d", &p[i], &n[i]);
	//������ �ݾװ� ���� 

	DP[0] = 1;



	for (i = 0; i < K; i++) {
		//�� ���� ������ ���� Ž�� 

		for (j = T; j >= 0; j--) {
			//������� �ϴ� ��


			for (l = 1; l <= n[i]; l++) {
				//�ش� ������ ����  
				if (j - p[i] * l >= 0)
					//���� ���Ƿ� �ִ� �� �� �ִ��� 

					DP[j] += DP[j - p[i] * l];
				else
					break;
			}
		}
	}

	//ó������ dp���� ���� ������ dp[0]=1�� �Ǿ�� �������� �� ������ ���� �����ϰ�
	//�̰� ��� �ݺ��Ǹ� �ᱹ ��... 

	printf("%d", DP[T]);


	return 0;
}