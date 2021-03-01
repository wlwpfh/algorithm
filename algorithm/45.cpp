#include<stdio.h>
#include<vector>
using namespace std;
int main45() {

	int i, n, k, num = 0;

	scanf("%d %d", &n, &k);

	vector <int>arr(n + 1);

	for (i = 0; i < n + 1; i++) {
		arr[i] = i;
	}

	int start = 0;

	int tmp_start = 0;
	int tmp_n = n;
	for (i = 0; i < n; i++) {
		start = start + k;
		if (tmp_n >= start)
			;
		else
			start = start % tmp_n;


		arr[start] = 0;

		tmp_start = start;
		for (tmp_start = tmp_start + 1; tmp_start < n + 1; tmp_start++) {
			arr[tmp_start - 1] = arr[tmp_start];
		}
		arr[n] = 0;
		printf("%d \n", start);
		tmp_n--;
	}

	for (i = 1; i < n + 1; i++) {
		if (arr[i] != 0)
			printf("%d", arr[i]);
	}

	return 0;
}