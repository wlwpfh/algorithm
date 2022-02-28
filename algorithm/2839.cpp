#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int sugar[5001];

int main() {

	scanf("%d", &N);

	sugar[3] = sugar[5] = 1;

	for (int i = 6; i <= N; i++) {
		if (sugar[i - 3] != 0)
			sugar[i] = sugar[i - 3] + 1;
		if (sugar[i - 5] != 0)
			if (sugar[i] == 0)
				sugar[i] = sugar[i - 5] + 1;
			else
				sugar[i] = min(sugar[i], sugar[i - 5] + 1);
	}

	if (sugar[N] == 0)
		printf("-1");
	else
		printf("%d", sugar[N]);

	return 0;
}