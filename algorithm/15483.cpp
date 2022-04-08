#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

char first[1004], second[1004];
int DP[1004][1004];
int main() {

	int i, j;

	scanf("%s", first);
	scanf("%s", second);

	//	printf("first:%d \n",strlen(first));
	//	printf("second:%d \n",strlen(second));

	int first_len = strlen(first);
	int second_len = strlen(second);

	//first�� y��, second�� x�࿡ �� ����  

	for (i = 0; i <= first_len; i++)
		DP[i][0] = i;

	for (i = 0; i <= second_len; i++)
		DP[0][i] = i;
	//���� ������ �������� x�� y�� �� �� i�� ���� �Ϸ� 

	for (i = 1; i <= first_len; i++) {
		for (j = 1; j <= second_len; j++) {
			if (first[i - 1] == second[j - 1])
				DP[i][j] = DP[i - 1][j - 1];
				//�� �� �״�� �������� 
			else
				DP[i][j] = min(min(DP[i - 1][j], DP[i][j - 1]), DP[i - 1][j - 1]) + 1;
				//����, ����, ���� �� �� �ϳ��� ���� ���� �Ÿ��� ���ϰ� �ű⿡ +1�ϱ� 
		}
	}


	printf("%d", DP[first_len][second_len]);

	return 0;
}