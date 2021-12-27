#include<stdio.h>
#include<queue>
using namespace std;

int main() {

	int n, tmp;
	priority_queue<int, vector<int>, greater<int> > pq;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		if (tmp != 0) {
			pq.push(tmp);
		}
		else {
			if (pq.empty()) {
				printf("0 \n");
			}
			else {
				printf("%d \n", pq.top());
				pq.pop();
			}
		}

	}

	return 0;
}