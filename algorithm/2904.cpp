#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX_NUM 1000000
using namespace std;

int N;
int arr[100];// ���� �Է� �� ����  
bool prime_check[MAX_NUM]; // �Ҽ� �Ǻ��� ���� 
vector<int> primes; //�Ҽ��� �� ����  
vector<vector<int> > prime_counts(100, vector<int>(primes.size(), 0)); // �ش� arr�� �Ҽ��� �׿� �ش��ϴ� ���� ����. 

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
		scanf("%d", &arr[i]); //���� ����  
	}
	makePrime(); //�Ҽ��� �Ǻ��Ͽ� primes�� �Ҽ��� ����. 

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
		//	printf("�Ҽ� %d : %d�� \n",i,primes_count[i]);
	}


	printf("%d %d", max_value, count);

	return 0;
}

//���μ������ϱ�, �װ� �����ϱ�,  