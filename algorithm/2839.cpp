#include<stdio.h> 

using namespace std;
int n, count = 0, min = 100000;
int arr[100];
int left_over(int num) {
	if (num < 0)
		return -1;
	else if (num == 0) {
		if (min > count)
			min = count;
		count = 0;
		return min;
	}
	else {
		if (num >= 3) {
			arr[num - 3] = left_over(num - 3);
			count++;
		}
		if (num >= 5) {

			arr[num - 5] = left_over(num - 5);
			count++;
		}
	}
}

int main() {
	scanf("%d", &n);

	int answer = left_over(n);

	printf("%d", answer);

	return 0;
}