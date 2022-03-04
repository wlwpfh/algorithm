#include<stdio.h>
#include<vector>
#include<cmath>
#define MAX_NUM 1000000
using namespace std;

int N;
int arr[100];// 들어온 입력 값 저장  
int prime_check[MAX_NUM]; // 소수 판별을 위해
vector<int> primes; //소수만 들어간 백터  
 // 해당 arr의 소수와 그에 해당하는 지수 저장. 

int total_prime[MAX_NUM]; //전체 해당 소수들 넣기  

void makePrime() {
	int i, j;

	for (i = 2; i <= MAX_NUM; i++)
		prime_check[i] = i;

	for (i = 2; i <= sqrt(MAX_NUM); i++) {
		if (prime_check[i] == 0)
			continue;

		for (j = i * i; j <= MAX_NUM; j += i)
			prime_check[j] = 0;
	}

	for (i = 2; i <= MAX_NUM; i++) {
		if (prime_check[i] != 0)
			primes.push_back(i);
	}

}

int main() {
	makePrime(); //소수를 판별하여 primes에 소수만 넣음. 

	int i, j, count = 0, max_value = 1, num;

	scanf("%d", &N);

	vector<vector<int> > prime_counts(N, vector<int>(primes.size(), 0));

	for (i = 0; i < N; i++) {
		scanf("%d", &num); //값을 저장  


		for (j = 0; j < primes.size(); j++) {
			if (num == 1)
				break;
			while (num % primes[j] == 0) {
				//입력값을 소수로 나눌 수 있다면 나누기  
				num /= primes[j];
				prime_counts[i][primes[j]]++;
				total_prime[primes[j]]++;
			}


		}
	}



	for (i = 0; i < primes.size(); i++) {
		int number = total_prime[primes[i]] / N;

		if (number != 0) {
			for (j = 0; j < N; j++) {
				if (prime_counts[j][primes[i]] < number) {

					count += (number - prime_counts[j][primes[i]]);

				}

			}
		}

		max_value *= pow(primes[i], number);
	}

	printf("%d %d", max_value, count);

	return 0;
}