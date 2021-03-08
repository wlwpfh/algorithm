#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int n, k; int i, count = 0, index = -1, curr;
	//bool is_finished=false;
	scanf("%d", &n);
	vector<int>arr(n + 1);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);

	int j = 1;
	while (count < k) { //일을 하기 
		if (j > n)
		{
			j = 1;
		}
		if (arr[j] != 0)
		{
			arr[j]--;
			count++;
		}
		j++;
	}

	for (i = 1; i <= n; i++) { //해당 순번 출력하기 
		if (arr[i] != 0)
		{
			printf("%d", i);
			return 0;
		}
	}

	printf("-1");
	return 0;
}