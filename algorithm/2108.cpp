#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int count[8001];
int main() {
	int n, freq = 0, count = 0, num = 0;
	scanf("%d", &n);
	int i, sum = 0;
	vector<int>arr(n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		if (arr[i] >= 0) {
			count[arr[i] + 4000]++;
		}
		else
			count[arr[i] - 4000]++;
	}
	sort(arr.begin(), arr.end());

	int freq = 0, num = 0;

	for (i = 0; i < 8001; i++) {
		if (count[i] > freq) {
			freq = count[i];
			num = i + 4000;
		}
	}


	printf("%.0f \n", round((double)sum / (double)n));
	printf("%d \n", arr[n / 2]);

	printf("%d \n", arr[n - 1] - arr[0]);

	arr.clear()
		arr.shrink_to_fit();

	return 0;
}