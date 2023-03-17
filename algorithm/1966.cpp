#include<stdio.h>
#include<queue>

using namespace std;

int T, N, M;

int main() {
	int tmp;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		priority_queue<int> pq;
		queue<pair<int, int>> q;
		scanf("%d %d", &N, &M);
		
		int count = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			pq.push(tmp);
			q.push(make_pair(j, tmp));
		}

		while (!pq.empty()) {

			int number = q.front().first;
			int priority = q.front().second;
			q.pop();
			if (pq.top() == priority) {
				count++;
				pq.pop();
				if (M == number)
					break;

			}
			else {
				q.push(make_pair(number, priority));
			}
		}
		printf("%d \n", count);

	}

	return 0;
}