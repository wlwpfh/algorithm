#include<stdio.h>
#include<map>

using namespace std;

map<int, int> m;
int N, M;

int main() {
	int tmp;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		m[tmp] = 1;
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);

		if (m[tmp] == 1)
			printf("1 ");
		else
			printf("0 ");
	}

	return 0;
}