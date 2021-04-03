#include<stdio.h>

int num;

//1부터 끝까지 출력하고 맨 마지막을 제외하고 출력하기
//그렇게 한 다음에 하나만 남으면 다음 수로 넘어가서 반복하기


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