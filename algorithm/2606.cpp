#include<stdio.h>

using namespace std;

int coms[101];

int Find(int v) {
	if (v == coms[v])
		return v;
	else
		return coms[v] = Find(coms[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a != b)
		if (a > b)
			coms[a] = b;
		else
			coms[b] = a;
}

int main() {
	int n, m, a, b, answer = 0;

	scanf("%d", &n); //7
	scanf("%d", &m); //6

	for (int i = 1; i <= n; i++)
		coms[i] = i;

	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		Union(a, b);

	}

	for (int i = 2; i <= n; i++) {
		if (Find(coms[i]) == Find(1))
			answer++;
	}
	printf("%d", answer);
	return 0;
}