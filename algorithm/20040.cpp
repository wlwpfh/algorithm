#include<stdio.h>
#include<vector>
#define MAX_N 500000
using namespace std;

int N, M;

int parent[MAX_N];

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	parent[Find(y)] = Find(x);
}

int main() {
	int i, a, b, x, y, answer = 0;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		parent[i] = i;

	for (i = 1; i <= M; i++) {
		//������ ��ȣ�� ����ϴ� ��
		scanf("%d %d", &a, &b);

		x = Find(a);
		y = Find(b);

		if (x == y) {
			//�̹� �θ� ���� �� 
			answer = i;
			break;
		}
		else {
			Union(a, b);
		}
	}

	printf("%d", answer);
	return 0;
}