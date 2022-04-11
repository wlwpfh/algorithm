#include<stdio.h>

using namespace std;

int N;

void makeStar(int n, int i, int j) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		printf(" ");
	//�ش� n�ȿ��� �� ���μ����� �߰��� �ִ� ��ĭ�̾�� �ϴϱ�  
	else if (n / 3 == 0)
		printf("*");
	//n�� 3���� ������ ���� ��찡 �ƴ� �� 	
	else
		makeStar(n / 3, i, j);
	//n�� �ɰ����鼭 ���� ������ �� ������  
}

int main() {

	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			makeStar(N, i, j);
		printf("\n");
	}


	return 0;
}