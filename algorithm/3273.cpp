#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, x, counts, sum;
vector<int> v;

void findX() {
	int left = 0, right = n - 1;
	while (left < right) {
		if (v[left] + v[right] == x) {
			counts++;
			left++;
			right--;
		}
		else if (v[left] + v[right] < x) {
			left++;
		}
		else {
			right--;
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	scanf("%d", &x);

	findX();

	printf("%d", counts);

	return 0;
}