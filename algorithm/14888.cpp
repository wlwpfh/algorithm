#include<stdio.h>

using namespace std;

int N, A[101];
bool number[101];
int cal[4];
//����, ����, ����, ������
int cal_count = 0;
int min = 987654321, max = 0, tmp;

//��Ʈ��ŷ�̴ϱ� 0�� �ƴ� �ͺ��� �ϱ� 
//�ٵ� �����ڰ� ��� �ٲ��� ��..  
void calculate(int number_index, int cal_index) {
	if (cal_count == 0) { //��� �����ڸ� �� ����ߴٸ�  
		min = min < tmp ? min : tmp;
		max = max > tmp ? max : tmp;

		return;
	}
	if (number[number_index] == false) {
		number[number_index] = true;
		//���⼭ ������ڸ� ����� ������ Ȯ���ؾ� ��
		//���ڴ� �״�� �����ڰ� brute force�� ����ϱ�
		if (cal[cal_index] == 0)
			tmp += number[number_index];
		else if (cal[cal_index] == 1)
			tmp -= number[number_index];
		else if (cal[cal_index] == 2)
			tmp *= number[number_index];
		else
			tmp /= number[number_index];
		cal_count--;
		calculate(number_index + 1, cal_index + 1);
		number[number_index] = false;
	}
}

int main() {
	int i;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	cal_count = N - 1;
	for (i = 0; i < 4; i++) {
		scanf("%d", &cal[i]);
	}


	calculate(1, 0);

	printf("%d \n %d", min, max);


	return 0;
}