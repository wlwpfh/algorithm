#include<stdio.h>
#include<string.h>

using namespace std;

char first[4004];
char second[4004];

int dp[4004][4004]; //어디서부터 어디까지 제일 긴 문자열인지 

//연속된 문자열이어야 함.  

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {

	int i, j, first_len, second_len, max_value = 0;

	scanf("%s", first);
	scanf("%s", second);

	first_len = strlen(first);
	second_len = strlen(second);


	for (i = 1; i <= first_len; i++) {
		for (j = 1; j <= second_len; j++) {
			if (first[i - 1] == second[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				max_value = max(max_value, dp[i][j]);
			}
			else
				dp[i][j] = 0;

		}
	} //겹치면 기존의 배열에서 +1하고 다르면 아예 0으로  


	printf("%d", max_value);

	return 0;
}