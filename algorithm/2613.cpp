#include<stdio.h>
#include<algorithm>
using namespace std;

int N, M;
int arr[300];

bool findMaxSum(int number) {

}

int main() {

	scanf("%d %d", &N, &M);
	int max_value = 0, sum = 0;
	//구슬에 적힌 숫자의 최댓값, N개의 입력의 합  
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		max_value = max(max_value, arr[i]);
		sum += arr[i];
	}

	int left = max_value - 1;
	int right = sum;


	while (left <= right) {
		int mid = (left + right) / 2;

		if (findMaxSum(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}

	printf("%d \n", left);
	//각 그룹을 말하기  


	// 다음 것이 max_value를 넘으면 포함시키지 말고 그룹이 끝났다고 하기
	//그 다음에 count++해서 count==M이면 일단 넘는지 안넘는지 확인하기 




	return 0;
}