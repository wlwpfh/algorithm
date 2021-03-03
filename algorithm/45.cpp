#include<stdio.h>
#include<vector>
using namespace std;
int main45_() {

	int i, n, k, num = 0;

	scanf("%d %d", &n, &k);

	vector <int>arr(n + 1);
	int pos = 0; int cnt = 0, bp = 0;
	while (1) {
		pos++;
		if (pos > n) pos = 1;
		if (arr[pos] == 0) {
			cnt++;
			if (cnt == k) {
				arr[pos] = 1;
				cnt = 0;
				bp++;
			}
		}

		if (bp == n - 1) break;
	}

	for (i = 1; i < n + 1; i++) {
		if (arr[i] == 0) {

			printf("%d", i);
			break;
		}
	}

	return 0;
}