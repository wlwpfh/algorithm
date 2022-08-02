#include<stdio.h>

using namespace std;

int N, tmp, ans_2, count;
long long k;
int arr[20], ans[20], result[20];
bool visited[20];

void DFS(int num) {
	if (num == N) {
		count++;
		for (int i = 0; i < N && k == 2; i++) {

			if (ans[i] == result[i])
				tmp++;
			else
				break;

		}

		if (count == tmp) {
			for (int i = 0; i < N; i++)
				result[i] = ans[i];
		} //1이 입력되었을 때  
		if (tmp == N) {
			ans_2 = count;
		}//2가 입력되었을 때  
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ans[num] = arr[i];
			DFS(num + 1);
			visited[i] = false;
		}
	}
}

int main() {
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		result[i] = 0;

	scanf("%lld", &k);

	if (k == 1) {
		scanf("%d", &tmp);
		for (i = 0; i < N; i++)
			arr[i] = i + 1;
	}
	else {

		for (i = 0; i < N; i++) {
			scanf("%d", &result[i]);
			arr[i] = i + 1;

		}
	}

	DFS(0);

	if (k == 1) {
		for (i = 0; i < N; i++)
			printf("%d ", result[i]);
	}
	else {
		printf("%d", ans_2);
	}

	return 0;
}