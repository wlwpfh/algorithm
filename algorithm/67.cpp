#include<stdio.h>
#include<vector>

using namespace std;

int cost = 100000, n, m;
int adlist[21][21], check[21];

void least_cost(int num, int sum) { //지금 현재 정점 
	int i;
	if (num == n) {
		if (cost > sum) {
			cost = sum;
		}
	}
	else { //다음 것 중에서 최소값이 무엇인지 
		for (i = 1; i <= n; i++) {
			if (adlist[num][i] > 0 && check[i] == 0) {
				check[i] = 1;
				least_cost(i, sum + adlist[num][i]);
				check[i] = 0;
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	int i, a, b, c;
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adlist[a][b] = c;
	}

	check[1] = 1;
	least_cost(1, 0);

	printf("%d", cost);

	return 0;
}