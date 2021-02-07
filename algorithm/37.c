#include<stdio.h>
int main37() {
	int num, i, j, k, work, income;

	scanf("%d %d", &num, &work);
	int pos;
	//num은 배열의 크기, work는 작업의 개  

	int arr[10] = { 0 }; //0으로 초기화 

	for (i = 0; i < work; i++) {
		scanf("%d", &income);

		pos = -1;

		for (j = 0; j < num; j++) {
			if (arr[j] == income) {
				pos = j; //hit인 경우 
			}
		}

		if (pos == -1) //miss인 경우
		{
			for (j = num - 1; j >= 1; j--) //맨 마지막 배열부터 시작 
			{
				arr[j] = arr[j - 1]; //맨 마지막 값은 자연스럽게 없어진다. 
			}
		}
		else { //hit인 경우 

			for (j = pos; j >= 1; j--) {
				arr[j] = arr[j - 1];
			}
		}
		arr[0] = income;
	}

	for (i = 0; i < num; i++)
		printf("%d ", arr[i]);
	return 0;
}