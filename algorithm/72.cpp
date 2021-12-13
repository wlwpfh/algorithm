#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int i, n, k;
	queue<int> q;
	scanf("%d %d", &n, &k);
	vector<int>check(n + 1);
	int tmp, count = 0;

	for (i = 1; i <= n; i++)
		q.push(i);

	while (q.size() != 1) {
		tmp = q.front();
		q.pop();
		count++;

		if (count == k) {
			count = 0;
		}
		else {
			q.push(tmp);
		}
	}
	printf("%d", q.front());
	return 0;
}