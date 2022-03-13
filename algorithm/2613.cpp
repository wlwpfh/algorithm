#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int arr[300];
int max_value;//현재ㅢ 최댓값 
bool findMaxSum(int mid) {
	int sum = 0, counts = 1;

	for (int i = 0; i < N; i++) {
		sum += arr[i];

		if (sum > mid) {
			sum = arr[i]; //이것만 들어가게 
			counts++;
		}
		//printf("sum:%d, mid:%d, count:%d \n",sum, mid, counts);
	}

	return counts <= M;
}

int main() {

	scanf("%d %d", &N, &M);
	int max_value = 0, sum = 0, i, ans = 0;
	//구슬에 적힌 숫자의 최댓값, N개의 입력의 합  
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		max_value = max(max_value, arr[i]);
		sum += arr[i];
	}

	int left = max_value;
	int right = sum;


	while (left <= right) {
		int mid = (left + right) / 2;

		if (findMaxSum(mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%d \n", left);
	//각 그룹을 말하기  
	sum = 0;
	for (i = 0; i < N; i++) {
		sum += arr[i];
		if (sum > left) {
			M--; //그룹 수를 세기 위해서 
			sum = arr[i];
			printf("%d ", ans);
			ans = 0; //다른 걸로 바꾸기 위해서  
		}
		ans++; //일단 모두 다 들어가게 하기 위해서 

		if (N - i == M)
			break;
		//하나씩 출력하기 위해서 

	}

	//남은 그룹에 하나씩  
	while (M) {
		printf("%d ", ans);
		ans = 1;
		M--;
	}



	return 0;
}