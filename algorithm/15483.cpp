#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

char first[1004], second[1004];
int DP[1004][1004];
int main() {

	int i, j;

	scanf("%s", first);
	scanf("%s", second);

	//	printf("first:%d \n",strlen(first));
	//	printf("second:%d \n",strlen(second));

	int first_len = strlen(first);
	int second_len = strlen(second);

	//first가 y축, second가 x축에 가 있음  

	for (i = 0; i <= first_len; i++)
		DP[i][0] = i;

	for (i = 0; i <= second_len; i++)
		DP[0][i] = i;
	//왼쪽 꼭짓점 기준으로 x축 y축 둘 다 i로 세팅 완료 

	for (i = 1; i <= first_len; i++) {
		for (j = 1; j <= second_len; j++) {
			if (first[i - 1] == second[j - 1])
				DP[i][j] = DP[i - 1][j - 1];
				//그 값 그대로 가져오기 
			else
				DP[i][j] = min(min(DP[i - 1][j], DP[i][j - 1]), DP[i - 1][j - 1]) + 1;
				//삽입, 수정, 삭제 셋 중 하나의 가장 작은 거리를 구하고 거기에 +1하기 
		}
	}


	printf("%d", DP[first_len][second_len]);

	return 0;
}