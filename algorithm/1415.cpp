#include<stdio.h>
#include<map>
using namespace std;

int N;
//int candy[50];
bool prime[500001];
long long dp[500001] = { 1, };
// 가격 업데이트용  
map <int, int> m;


void checkPrime() { //에라토스테네스의 체  
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
// * 주의사항 
//	1.사탕가격 0인 경우, 가격이 같은 사탕이 여러 개 있을 경우는 어떻게 취급해야 할까?
//	2.총 경우의 수는 매우 큰 값일 수 있으므로 long long 사용

int main() {

	int i, candy, j, k;
	long long count = 0, sum = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d", &candy);

		m[candy]++;
		sum += candy; //모든 사탕의 합 	
	}

	//	for(pair<int,int> p: m){
	//		printf("%d-> %d \n",p.first, p.second);
	//	} //넣기 확인 	

	checkPrime();
	//에라토스테네스의 체 

	m[0]++;

	for (pair<int, int> p : m) {
		//printf("현재의 p: %d \n",p.first);
		if (p.first == 0)
			continue;
		for (i = sum; i >= 0; i--) {
			//중복을 피하기 위해 높은 가격부터   
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