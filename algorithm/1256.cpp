#include<string>
#define MAXN 100
#define MAXK 1000000000
using namespace std;

int dp[MAXN * 2 + 1][MAXN + 1];
//n�� ���� Ŭ ���̰� n+m�� �غ��� 2n�� ���ų� �۱� ������ 2maxn+1�� ��������. 

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	n += m;
	//n�� a�� ����, m�� z�� ����
	//���� n�� a�� z�� ������ ��ģ ��  
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		//������ �� iC0�� 1�̴ϱ�  
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

			if (dp[i][j] > MAXK)
				dp[i][j] = MAXK;
			//�ش� ���� �Ѿ ���  
		}
	} //�������� Ǫ�� ��  
	//nCr= n-1Cr-1 +n-1Cr;
	//a�� z�� �̿��Ͽ� ���� �� �ִ� ������  

	if (dp[n][m] < k) {
		printf("-1 \n");
		return 0;
	}//���ڿ��� ���̰� k���� �ȵǴ� ���
	//�� �ߴµ� ���� �� �ִ� �������� �� ���� ���   

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}

	while (n) {
		//���̰� n�̴ϱ� ���� �ϳ��� ���
		//k��° ���ڿ�   
		if (dp[n - 1][m] >= k)
			printf("a");
		//
		else {
			printf("z");
			k -= dp[n - 1][m--];

		}


		n--;
		//���̸� �ϳ��� �ٿ�������.  
	}



	return 0;
}