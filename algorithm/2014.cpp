#include<stdio.h>
#include<queue>
using namespace std;

int main() {

	int n, k, tmp, count = 0;
	priority_queue<int, vector<int>, greater<int> > pq;

	scanf("%d %d", &n, &k);

	vector<int> mul;

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		pq.push(tmp);
		mul.push_back(tmp);
	}

	while (count != k) {
		// pop하고
		int min = pq.top();
		pq.pop();

		//다른 수를 꺼내서 곱하기 -> push한 다음에 vector에 넣기
		// -> index가 k인 것을 뽑기  

	}




	return 0;
}