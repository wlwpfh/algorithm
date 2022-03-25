#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

char first[17005];
char second[17005];
int DP[17005][17005];

vector<pair<char, char> >forPrint;

int main() {

	int i, j, first_len, second_len;

	scanf("%s", first);
	scanf("%s", second);

	first_len = strlen(first) + 1;
	second_len = strlen(second) + 1;

	printf("first: %d, second: %d \n", first_len, second_len);

	for (i = 0; i <= first_len; i++)
		DP[i][0] = i;


	for (i = 0; i <= second_len; i++)
		DP[0][i] = 0;

	for (i = 1; i <= first_len; i++) {
		for (j = 1; j <= second_len; j++) {
			if (first[i - 1] == second[j - 1])
				DP[i][j] = DP[i - 1][j - 1];
			else
				DP[i][j] = 1 + min(min(DP[i - 1][j - 1], DP[i - 1][j]), DP[i][j - 1]);
		}
	}


	for (i = 0; i <= first_len; i++) {
		for (j = 0; j <= second_len; j++)
			printf("%d ", DP[i][j]);
		printf("\n");
	}


	return 0;
}