#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int counts[8001] = { 0, };
vector<int> v;

//첫번째는 count개수, 두번째는 값  
int main() {
	int n, freq = 1, num = 0;
	scanf("%d", &n);
	int i, sum = 0;
	vector<int>arr(n);
	int freq_num = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];

		counts[arr[i] + 4000]++;

		if (counts[arr[i] + 4000] >= freq) {
			freq = counts[arr[i] + 4000];

		}

	}
	sort(arr.begin(), arr.end());



	bool isSecond = false;

	for (i = 0; i <= 8000; i++) {
		if (counts[i] == freq) {

			freq_num = i - 4000;

			if (isSecond)
				break;


			isSecond = true;
		}
	}



	printf("\n1. %.0f \n", round((double)sum / (double)n));
	printf("2. %d \n", arr[n / 2]);
	printf("3. %d \n", freq_num);
	printf("4. %d \n", arr[n - 1] - arr[0]);



	return 0;
}