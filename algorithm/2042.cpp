#include<stdio.h>

using namespace std;

long long lla[1000001];

int main() {
	int n, m, k, tmp;
	long long answer;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		lla[i] = tmp;
	}

	printf("%lld", answer);
	return 0;
}