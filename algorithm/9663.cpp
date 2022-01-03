#include<stdio.h>
#include<cmath>
using namespace std;

int n, answer = 0;
int col[15];
bool check(int row) {
	//�밢�� üũ�ϱ�, ���� Į���� �ִ� �� üũ�ϱ�
	for (int i = 0; i < row; i++) {
		if (col[i] == col[row] || abs(col[row] - col[i]) == row - i)
			return false;
	}
	return true;
}

void backTracking(int c) {
	if (c == n) {
		answer++;
		return;
	}

	for (int i = 0; i < n; i++) {
		col[c] = i;

		if (check(c))
			backTracking(c + 1);
	}
}

int main() {
	scanf("%d", &n);

	backTracking(0);

	printf("%d", answer);

	return 0;
}