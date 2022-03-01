#include<stdio.h>
#include<algorithm>
#define MAX_N 1000000
using namespace std;

int N;
pair<int, int> arr[MAX_N];
int ans[MAX_N];
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first = b.first;
	return a.second < b.second;
}

int main() {
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		arr[i].first = i;
		scanf("%d", &arr[i].second);
	}

	sort(arr, arr + N, compare);

	for (i = 0; i < N; i++) {
		printf("숫자:%d, 원래 index:%d, 현재 index:%d \n", arr[i].second, arr[i].first, i);

	}

	return 0;
}