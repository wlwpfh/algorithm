#include<stdio.h>

using namespace std;

int arr[21];
bool visited[21];
int result[21];
int N, k, count, tmp;

void DFS(int num) {
	if (count == tmp || num == N + 1) {
		return;
	}
	printf("num=%d \n", num);
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			result[num] = arr[i];
			DFS(num + 1);
			visited[i] = false;
		}
	}
	count++;
}

int main() {
	int i;

	scanf("%d", &N);

	scanf("%d", &k);

	if (k == 1) {
		scanf("%d", &tmp);
	}
	else {
		for (i = 0; i < N; i++)
			scanf("%d", &arr[i]);
	}

	if (k == 1) {
		DFS(1);
		for (i = 1; i <= N; i++)
			printf("%d ", result[i]);
	}
	else {
		;
	}

	return 0;
}