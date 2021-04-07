#include<stdio.h>

void subset(int*);
int num, index = 1, left = 0, right = 0;
int check[11];

void subset(int* arr) {
	left = 0, right = 0;
	int i;
	if (index == num + 1)
	{
		for (i = 1; i <= num; i++) {
			if (check[i] == 1)
				left = left + arr[i];
			else
				right = right + arr[i];
		}
		if (left == right)
			printf("YES");
		else
			printf("NO");
		return;
	}

	check[index] = 1;
	subset(&arr[index + 1]);
	check[index] = 0;
	subset(&arr[index + 1]);
}
int main() {

	int i;
	int arr[11];
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		scanf("%d", arr[i]);
	}

	subset(&arr[1]);

	//	if(left==right)
	//		printf("YES \n");
	//	else
	//		printf("NO \n");

	return 0;
}