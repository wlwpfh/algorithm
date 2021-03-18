#include<stdio.h>
#include<vector>

using namespace std;

int main50_() {
	int n, m, i, j, h, w, s, k, max = 0, sum = 0;

	scanf("%d %d", &n, &m);

	vector<vector<int> > arr(n, vector<int>(m));

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d %d", &h, &w);

	for (i = 0; i < n - h + 1; i++) {
		for (j = 0; j < m - w + 1; j++) {
			sum = 0;

			for (s = i; s < i + h; s++)
				for (k = j; k < j + w; k++)
					sum = sum + arr[s][k];
			if (sum > max)
				max = sum;

		}
	}

	printf("%d", max);

	return 0;
}