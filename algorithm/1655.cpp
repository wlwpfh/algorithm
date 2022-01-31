#include<stdio.h>
#include<queue>
#define MAX_N 100000
using namespace std;

priority_queue<int> pq_l; // 3 2 1
priority_queue<int, vector<int>, greater<int> > pq_r; // 4 5 6

int main() {
	int N, a;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &a);
		if (pq_l.size() > 0 && pq_l.top() > a)
			pq_l.push(a);
		else
			pq_r.push(a);

		while (1) {
			if (i % 2 == 0 && pq_r.size() == pq_l.size())
				break;
			else if (i % 2 == 1 && pq_r.size() == pq_l.size() + 1)
				break;

			if (pq_r.size() > pq_l.size()) {
				int tmp = pq_r.top();
				pq_r.pop();
				pq_l.push(tmp);
			}
			else {
				int tmp = pq_l.top();
				pq_l.pop();
				pq_r.push(tmp);
			}


		}


		if (i % 2 == 0)
			printf("%d \n", pq_l.top());
		else
			printf("%d \n", pq_r.top());
	}

	return 0;
}