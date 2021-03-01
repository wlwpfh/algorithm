#include<stdio.h>
#include<vector>
using namespace std;
int main44() {

	int i, n, k, num = 0;

	scanf("%d %d", &n, &k);

	vector <int>arr(n + 1);
	vector <int>exclude(n + 1);
	int count = 1;
	for (i = 1; i <= n; i++) {
		arr[i] = i;
	}

	for (i = 1; i <= n - 1; i++) //한명씩 거르기
	{
		count++;

		if (count == 3) {


			count = 1;
		}
	}

	printf("%d", num);

	return 0;
}