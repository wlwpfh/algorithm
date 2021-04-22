#include<stdio.h>
#include<vector>

using namespace std;

int n, m, count;
int check[30];
vector<int> adlist[30];

void path_finding(int num) {
	int i;
	if (num == n) {
		count++;

		for (i = 0; i < num; i++)
			if (check[i] == 1)
			{
				printf("%d ", i);
			}
		printf("5");
		printf("\n");

	}
	else {
		for (i = 0; i < adlist[num].size(); i++) {
			if (check[adlist[num][i]] == 0) {
				check[adlist[num][i]] = 1;
				path_finding(adlist[num][i]);
				check[adlist[num][i]] = 0;
			}
		}
	}
}
int main() {

	int i, a, b;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		adlist[a].push_back(b);
	}
	check[1] = 1;
	path_finding(1);

	printf("%d \n", count);
	return 0;
}