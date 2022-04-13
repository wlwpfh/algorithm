#include<stdio.h>
#include<algorithm>

using namespace std;

int N, M, tmp_diff;
int arr[5002];

int findArea(int num) {
	//최소의 값이 될 수 있는지  
	int counts = 1, left = arr[0], right = arr[0];
	//그냥 일단 값 초기화  
	for (int i = 1; i < N; i++) {
		if (arr[i] < left)
			left = arr[i];
		if (arr[i] > right)
			right = arr[i]; //현재까지 중에서 제일 그거인 그거를 찾으니까
		//현재 시작 구간부터 i번째 구간까지 제일 큰 값과 제일 작은 값을 구하는 과정  

		if ((right - left) > num) {
			left = arr[i];
			right = arr[i];
			counts++;
			//하나 더 해주고 초기화  
		}
	}

	return counts <= M;
}

int main() {

	int i, max_value = 0, res = 987654321;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		max_value = max(max_value, arr[i]);
	}

	int left = 0, right = max_value, mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (findArea(mid)) {
			right = mid - 1;
			res = min(res, mid);
			//mid가 가장 작은 차이니까 그거를 res에 저장하기  
		}
		else
			left = mid + 1;

	}
	printf("%d", res);

	return 0;
}