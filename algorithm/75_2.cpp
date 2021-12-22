#include<queue>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

struct Data {
	int money;
	int when;
	Data(int a, int b) {
		money = a;
		when = b;
	}
	bool operator<(Data& b) {
		return when > b.when;
	}
};

int main() {
	int n, i, j, a, b, res = 0, max = -1000;
	// ������ ���� �������� �˱� ���ؼ�  
	vector<Data> T;
	priority_queue<int> pq;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		T.push_back(Data(a, b));
		if (b > max)
			max = b;
	}
	sort(T.begin(), T.end());



	j = 0;
	for (i = max; i >= 1; i--) {
		for (; j < n; j++) {
			if (T[j].when < i) break; //��¥�� �� ũ�� �ȵǴϱ� 
			pq.push(T[j].money);
		}

		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}


	printf("%d", res);

	return 0;
}