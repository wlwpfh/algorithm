#include<stdio.h>
#include<vector>
using namespace std;
int main() {

	int i, j, tmp, num, count = 0;
	scanf("%d", &num);

	vector <int> arr(num + 1);
	vector <int> sorted(num + 1);
	for (i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
	}  
	//순서와 무엇이 더 큰지 확인하기
	for (i = 1; i <= num; i++) {
		tmp = arr[i];



		for (j = 1; j <= i; j++) {
			if (tmp < sorted[j]) {
				count++; //나보다 더 큰 수가 얼마나 있는지 
			}
		}

		for (j = tmp + 1; j <= num; j++) {
			if (sorted[j] != 0) { //이미 차잇는 경우 
				;
			}
			else { //비어있는 경우 
				sorted[j] = i;
			}
		}
		count++;
	}

	for (i = 1; i <= num; i++) {
		printf("%d ", sorted[i]);
	}

	return 0;
}