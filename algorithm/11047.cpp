#include<stdio.h>
#define MAX_SIZE 10

using namespace std;

int arr[MAX_SIZE + 1];
int N, K, count, res;

int main() {
	int max_index, i;
	scanf("%d %d", &N, &K);
	res = K;
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		if (K >= arr[i])
			max_index = i;
	}
	int index = max_index;
	while (res != 0) {
		res -= arr[max_index];
		count++;
		printf("res: %d \n", res);
		for (i = 0; i <= index; i++) {
			if (res >= arr[i])
				max_index = i;
		}
		index = max_index;


	}

	printf("%d", count);

	return 0;
}