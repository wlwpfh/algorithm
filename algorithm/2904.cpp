#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX_NUM 1000000
using namespace std;

int N;
int arr[100];// 들어온 입력 값 저장  
bool prime_check[MAX_NUM]; // 소수 판별을 위해 
vector<int> primes; //소수만 들어간 백터  
vector<vector<int> > prime_counts(100, vector<int>(primes.size(), 0)); // 해당 arr의 소수와 그에 해당하는 지수 저장. 

void makePrime() {
	int i, j;


	for (i = 2; i <= MAX_NUM; i++) {
		if (prime_check[i] == true)
			continue;
		for (j = i * i; j <= MAX_NUM; j += i)
			prime_check[j] = true;
	}

	for (i = 2; i <= MAX_NUM; i++)
		if (prime_check[i] == false)
			primes.push_back(i);
	printf("primes.size():%d \n", primes.size());
}

int main() {
	int i, j, max_value = 0, count = 0;



	scanf("%d", &N);


	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]); //값을 저장  
	}
	makePrime(); //소수를 판별하여 primes에 소수만 넣음. 

	printf("primes size:%d \n", primes.size());

	for (i = 0; i < N; i++) {
		for (j = 0; j < primes.size(); j++) {

			while (arr[i] % primes[j] == 0) {
				prime_counts[i][j]++;
				arr[i] /= primes[j];

				printf("arr[i]:%d, primes_count[%d][%d]=%d \n", arr[i], i, j, prime_counts[i][j]);

				if (arr[i] == 1)
					break;

			}
			if (arr[i] == 1)
				break;
		}
	}



	for (i = 0; i < MAX_NUM; i++) {
		//if(primes_count[i]!=0)
		//	printf("소수 %d : %d개 \n",i,primes_count[i]);
	}


	printf("%d %d", max_value, count);

	return 0;
}

//소인수분해하기, 그걸 저장하기,  