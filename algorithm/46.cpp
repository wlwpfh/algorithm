#include<stdio.h>
#include<vector>
using namespace std;
int main46_() {
	int n, k; int i, count = 0;
	int sum = 0;
	scanf("%d", &n);
	vector<int>arr(n + 1);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum = sum + arr[i];
	}
	scanf("%d", &k);
	if (k >= sum) {
		printf("-1");
		return 0;
	}
	int j = 1;
	while (1) { //일을 하기 
		if (j > n)
		{
			j = 1;
		}
		if (arr[j] != 0)
		{
			arr[j]--;
			count++;
		}
		if (count == k)
			break;
		j++;
	}
	while (1) {
		j++;
		if (j > n)
			j = 1;
		if (arr[j] != 0)
			break;

	}
	printf("%d", j);
	return 0;
}