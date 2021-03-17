#include<stdio.h>
#include<vector>

using namespace std;

int main() {
	int n, m, i, j, tmp, max = 0, sum = 0;

	scanf("%d %d", &n, &m);

	vector<vector<int> > arr(n, vector<int>(m));

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	//i대신해서 사용 
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < m - 2; j++) {
			sum = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];


			if (sum > max)
				max = sum;

		}



	}

	printf("%d", max);

	return 0;
}