#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int i, n, k, sum = 0;
	queue<int> Q;
	scanf("%d %d", &n, &k);
	vector<int>check(n + 1);

	int count = 0, past, num, curr = k;
	check[k] = 1;

	Q.push(k);
	while (1) {
		count = 0;
		if (Q.size() == n - 1)
			break;
		if (k + curr > n) {
			past = curr;
			curr = (k + curr) % n;
			printf("curr: %d \n", curr);
		}
		else {
			past = curr;
			curr = curr + k;
		}
		//	printf("���� ���: %d \n",curr);
		for (i = past + 1; i < curr; i++) {
			if (check[i] == 1) {
				count++;
			}

		}
		printf("%d�� %d���̿� %d���� üũ�� ���� �ִ� \n", past + 1, curr, count);
		if (check[curr + count] == 0) {
			check[curr] = 1;
			Q.push(curr);
			printf("�� ��: %d \n", curr);

		}

	}
	for (i = 1; i < check.size(); i++) {
		if (check[i] == 0)
			printf("%d ", i);
	}
	return 0;
}