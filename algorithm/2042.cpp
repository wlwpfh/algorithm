#include<stdio.h>
#define MAX_SIZE 1000000
using namespace std;

long long n, m, k, b;
long long lla[MAX_SIZE];
// ��� ��ü�� long�� ���� �ʴ´�.  

void init() {
	// Ʈ�� �ȿ� �� ����ֱ� 
	for (int i = b - 1; i > 0; i--) {
		lla[i] = (lla[i << 1] + lla[(i << 1) + 1]);
	}
}

void update() {
	//�ڱ� ���� �迭�� ������Ʈ��Ű�� 
}

int main() {
	int tmp;
	long long answer;
	scanf("%d %d %d", &n, &m, &k);

	for (b = 1; b < n; b <<= 1);
	//b�� ���� 8�� �Ǿ �ش� ���� �ȴ�. 

	for (int i = b; i < n + b; i++) {
		scanf("%lld", &lla[i]);
	}

	init();



	printf("%lld", answer);
	return 0;
}