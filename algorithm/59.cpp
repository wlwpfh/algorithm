#include<stdio.h>

int num;

void subset(int n) {
	if (n > num)
	{
		return;
	}
	else {
		printf("%d ", n);
		subset(n + 1);

	}
}
int main() {


	scanf("%d", &num);
	subset(1);

	//부분집합의 개수: 2의 num승의 -1 (공집합은 빼니까) 

	return 0;
}