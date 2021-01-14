#include<stdio.h>
int main4() {

	int n=0; //입력될 사람의 수
	
	scanf("%d", &n);

	int max=-200; int min=200;

	int age;

	for (int i = 0; i < n; i++) {
		scanf("%d", &age);
		
		if (max < age) {
			max = age;
		}
		if (min > age) {
			min = age;
		}
	}

	printf("%d", max - min);


	return 0;
}