#include<stdio.h>
#include<vector>

using namespace std;

vector<pair<int, int> >adlist[21];
int n, m, cost = 10000;
int check[21];
void least_cost(int num, int sum) {
	int i;
	if (num == n) {
		if (cost > sum)
			cost = sum;
	}
	else {
		for (i = 0; i < adlist[num].size(); i++) {
			if (check[adlist[num][i].first] == 0) {
				check[adlist[num][i].first] = 1;
				least_cost(adlist[num][i].first, sum + adlist[num][i].second);
				check[adlist[num][i].first] = 0;
			}
		}
	}
}
int main() {
	int i, a, b, c;
	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adlist[a].push_back(make_pair(b, c));
	}
	check[1] = 1;
	least_cost(1, 0);

	printf("%d", cost);

	return 0;

}