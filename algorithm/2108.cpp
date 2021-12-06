#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int n, freq = 0, count = 0, num = 0;
	scanf("%d", &n);
	int sum = 0;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				freq++;
			}
			if (freq >= count) {
				num = arr[i];
				count = freq;
			}

		}
	}



	printf("%.0f \n", round((double)sum / (double)n));
	printf("%d \n", arr[n / 2]);
	if (freq == 0) printf("%d \n", arr[1]);
	else printf("%d \n", num);
	printf("%d \n", arr[n - 1] - arr[0]);

	arr.clear()
		arr.shrink_to_fit();

	return 0;
}