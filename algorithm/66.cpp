#include<stdio.h>
#include<vector>

using namespace std;

int n, m, count;

vector<pair<int, int> > adlist[30];

void path_finding(int num) {
	int i;
	if (num == n) {
		count++;
	}
	else {
	}

	int main() {

		int i, a, b;

		scanf("%d %d", &n, &m);

		for (i = 1; i <= m; i++) {
			scanf("%d %d", &a, &b);
			adlist[i].push_back({ a,b });
		}

		path_finding(1);

		printf("%d \n", count);
		return 0;
	}