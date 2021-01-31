#include<stdio.h>
#include<algorithm>
int main24() {
	int check[100] = { 0, };

	int num, first, second, diff;
	int pow;
	scanf("%d", &num);

	scanf("%d", &first);

	for (int i = 1; i < num; i++) {
		scanf("%d", &second);
		diff = second - first;
		pow = abs(diff);


		if (check[pow] == 0 && pow > 0 && pow < num)
			check[pow] = 1;
		else {
			printf("NO \n"); //해당하지 않다면 바로 출력하고 return 0 
			return 0;
		}

		first = second;
	}
	printf("YES \n");

	return 0;
}