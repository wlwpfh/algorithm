#include<stdio.h>

int array[11];
int num;

void subset(int n) {
	int i;
	if (n == num + 1) {
		for (i = 1; i <= n; i++) {
			if (array[i] == 1)
				printf("%d ", i);
		} //1로 된 것들을 출력해야 하니까 
		printf("\n");
		return;
	}
	else {
		array[n] = 1; //왼쪽 자식
		subset(n + 1);
		array[n] = 0;
		subset(n + 1);
	}

}
int main() {


	scanf("%d", &num);
	subset(1);


	return 0;
}