#include<stdio.h>
#include<vector>

using namespace std;

int main() {
	int num, i, min = 1000000, j = 1, index, k;

	scanf("%d", &num);

	vector<int>arr(num + 1);
	vector<int>arranged(num + 1);

	for (i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);

		if (arr[i] > min && arr[i] != 0)
			min = arr[i]; //첫 최솟값을 구함 
		index = i;
	}

	for (j = 1; j <= num; j++) {
		arr[index] = 0;
		arranged[j] = min;
		j++;



		printf("%d ", arranged[j]);

		min = arr[index + 1];

		for (k = 1; k <= num; k++) {
			if (arr[k] > min && arr[k] != 0) {
				min = arr[k];
			}
		}

	}


	return 0;
}