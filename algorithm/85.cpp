#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int add, mi, mul, di, min_value = 987654321, max_value = -987654321;
int arr[11];

int Calculate(int index, int sum) {
	if (index == N) {
		min_value = min(min_value, sum);
		max_value = max(max_value, sum);
	}
	else {
		if (add > 0) {
			add--;
			Calculate(index + 1, sum + arr[index + 1]);
			add++;
		}
		if (mi > 0) {
			mi--;
			Calculate(index + 1, sum - arr[index + 1]);
			mi++;
		}
		if (mul > 0) {
			mul--;
			Calculate(index + 1, sum * arr[index + 1]);
			mul++;
		}
		if (di > 0) {
			di--;
			Calculate(index + 1, sum / arr[index + 1]);
			di++;
		}
	}
}

int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d %d %d", &add, &mi, &mul, &di);

	Calculate(1, arr[1]);

	printf("%d \n", max_value);
	printf("%d \n", min_value);

	return 0;
}