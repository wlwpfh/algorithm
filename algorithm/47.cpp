#include<stdio.h>
#include<vector>
using namespace std;
int main47_() {
	int n, i, j;
	int tmp;
	int count = 0;

	scanf("%d", &n);
	vector<vector<int> > arr(n + 2, vector<int>(n + 2));


	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}



	tmp = 1;
	//가로로 큰 것 중에 세로에서도 큰 지 확인하기 
	for (i = 1; i <= n; i++) {
		for (tmp = 1; tmp <= n; tmp++)
		{

			if (arr[i][tmp - 1]<arr[i][tmp] && arr[i][tmp]>arr[i][tmp + 1]) {
				if (arr[i - 1][tmp]<arr[i][tmp] && arr[i][tmp]>arr[i + 1][tmp]) {
					count++;
				}
			}
		}

	}

	printf("%d", count);

	return 0;
}