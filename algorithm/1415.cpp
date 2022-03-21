#include<stdio.h>
#include<map>
using namespace std;

int N;
//int candy[50];
bool prime[500001];
long long dp[500001] = { 1, };
// ���� ������Ʈ��  
map <int, int> m;


void checkPrime() { //�����佺�׳׽��� ü  
	int i, j;
	for (i = 2; i <= 500000; i++) {
		prime[i] = true;
	}
	for (i = 2; i * i <= 500000; i++) {
		if (prime[i] == false)
			continue;
		for (j = i * i; j <= 500000; j += i)
			prime[j] = false;
	}
}
// * ���ǻ��� 
//	1.�������� 0�� ���, ������ ���� ������ ���� �� ���� ���� ��� ����ؾ� �ұ�?
//	2.�� ����� ���� �ſ� ū ���� �� �����Ƿ� long long ���

int main() {

	int i, candy, j, k;
	long long count = 0, sum = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d", &candy);

		m[candy]++;
		sum += candy; //��� ������ �� 	
	}

	//	for(pair<int,int> p: m){
	//		printf("%d-> %d \n",p.first, p.second);
	//	} //�ֱ� Ȯ�� 	

	checkPrime();
	//�����佺�׳׽��� ü 

	m[0]++;

	for (pair<int, int> p : m) {
		//printf("������ p: %d \n",p.first);
		if (p.first == 0)
			continue;
		for (i = sum; i >= 0; i--) {
			//�ߺ��� ���ϱ� ���� ���� ���ݺ���   
			for (j = 1; j <= m[p.first]; j++) {
				//printf("m[p.first]=m[%d]=%d \n",p.first, m[p.first]);
				if (i - (p.first * j) >= 0) {
					//printf("j:%d, p.first:%d, k:%d \n",j,p.first,k);
					dp[i] += dp[i - (p.first * j)];
					///printf("dp[%d](%d)+=dp[%d-%d*%d](%d) \n"
					//,j, dp[j], j,p.first, k, dp[j-p.first*k]);	
				}
				else
					break;

			}
		}


	}


	//	for(i=2;i<=sum;i++){
	//		if(dp[i]!=0)
	//			printf("%d : %d \n",i,dp[i]);
	//	}

	for (i = 2; i <= 500000; i++)
		if (prime[i] == true)
			count += dp[i];

	if (m[0] != 0)
		printf("%lld", count * m[0]);
	else
		printf("%lld", count);

	return 0;
}