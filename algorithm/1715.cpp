#include<stdio.h>
#include<queue>
using namespace std;

int main() {
	int n, tmp, answer = 0;
	priority_queue <int, vector<int>, greater<int> > pq;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		pq.push(tmp);
	}

	while (pq.size() != 1) {
		int min = pq.top();
		pq.pop();
		int max = pq.top();
		pq.pop();
		pq.push(min + max);
		//printf("%d + %d = %d \n",min, max, min+max);
		answer += min + max;

	}

	printf("%d", answer);

	return 0;
}