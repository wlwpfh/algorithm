#include<stdio.h>
#include<queue>

using namespace std;

int T;
priority_queue<int> pq_l;
priority_queue<int, vector<int>, greater<int> >pq_r;
int main() {
	scanf("%d", &T);
	int i, j, M, a;
	for (i = 0; i < T; i++) {
		scanf("%d", &M);

		printf("%d\n", M / 2 + 1);

		for (j = 1; j <= M; j++) {
			scanf("%d", &a);

			if (pq_l.size() > 0 && pq_l.top() > a)
				pq_l.push(a);
			else
				pq_r.push(a);

			while (1) {
				if (j % 2 == 0 && pq_r.size() == pq_l.size()) {
					break;
				}
				else if (j % 2 == 1 && pq_r.size() == pq_l.size() + 1) {
					printf("%d ", pq_r.top());
					if (j % 10 == 0)
						printf("\n");
					break;
				}

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

		}

		while (!pq_l.empty())
			pq_l.pop();
		while (!pq_r.empty())
			pq_r.pop();

	}
	return 0;
}