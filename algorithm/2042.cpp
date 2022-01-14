#include<stdio.h>
#include<algorithm>
#define MAX_SIZE 1000000
using namespace std;

long long n, m, k, b, sum;
long long lla[MAX_SIZE];
// ��� ��ü�� long�� ���� �ʴ´�.  

void init() {
	// Ʈ�� �ȿ� �� ����ֱ� 
	for (int i = b - 1; i > 0; i--) {
		lla[i] = (lla[i << 1] + lla[(i << 1) + 1]);
	}
}
void print(int start, int end) {
	//-Start �� ���
	//Index �� Ȧ�� �� ��� : Max�� ���� �� �θ���� �̵�
	//Index�� ¦���� ��� : ���� ���� �θ� ���� �̵�
	//
	//- End �� ���
	//Index �� Ȧ�� �� ��� : ���� ���� �θ� ���� �̵�
	//Index�� ¦���� ��� : Max�� ���� �� �θ���� �̵�

	while (start <= end) {
		if (start % 2 == 1)
			sum = max(lla[start], sum);
		if (end % 2 == 0)
			sum = max(lla[end], sum);

		start = (start + 1) / 2;
		end = (end - 1) / 2;

	}

}
void update(int i1, int i2) {
	long long tmp = lla[i1];
	lla[i1] = lla[i2];
	lla[i2] = tmp;
	//�ڱ� ���� �迭�� ������Ʈ��Ű�� 
	for (int i = b - 1; i > 0; i--) {
		lla[i] = (lla[i << 1] + lla[(i << 1) + 1]);
	}
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
	int a1, b1, c1;
	for (int i = 0; i < m + k; i++) {
		scanf("%d %d %d", &a1, &b1, &c1);
		if (a1 == 1) {
			update(b1, c1);

		}
		else { //a==2�� ���  
			print(b1, c1);
			printf("%d \n", sum);
		}
	}


	return 0;
}