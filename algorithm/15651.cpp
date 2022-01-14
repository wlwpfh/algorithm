#include<stdio.h>
#include<string.h>
using namespace std;

int n, m;

bool visit[10] = { 0, };
int arr[10] = { 0, };
void backTracking(int count) {
	//���� ����, �ش� ���� ����  
	if (count == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			arr[count] = i;
			visit[i] = false;
			backTracking(count + 1);
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);


	backTracking(0);

	return 0;
}