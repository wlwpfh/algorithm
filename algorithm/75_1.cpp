#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n;
priority_queue<int> pq;
vector<pair<int, int> > sch;

bool compare(pair<int, int>i, pair<int, int>j) {
	return i.second > j.second;
}

int main() {
	int i, j, a, b, max = -1000, sum = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		sch.push_back(make_pair(a, b));

		if (b > max)
			max = b;
	}

	sort(sch.begin(), sch.end(), compare);

	j = 0;
	for (i = max; i >= 1; i--) {
		for (; j < n; j++) {
			if (sch[j].second < i) break; //날짜가 더 크면 넣지 말기
			pq.push(sch[j].first);
		}

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}


	printf("%d", sum);

	return 0;
}