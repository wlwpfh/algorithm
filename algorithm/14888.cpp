#include<stdio.h>

using namespace std;

int N, A[101];
bool number[101];
int cal[4];
//덧셈, 뺄셈, 곱셈, 나눗셈
int cal_count = 0;
int min = 987654321, max = 0, tmp;

//백트레킹이니까 0이 아닌 것부터 하기 
//근데 연산자가 계속 바뀌어야 함..  
void calculate(int number_index, int cal_index) {
	if (cal_count == 0) { //모든 연산자를 다 사용했다면  
		min = min < tmp ? min : tmp;
		max = max > tmp ? max : tmp;

		return;
	}
	if (number[number_index] == false) {
		number[number_index] = true;
		//여기서 어떤연산자를 사용할 것인지 확인해야 함
		//숫자는 그대로 연산자가 brute force로 사용하기
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