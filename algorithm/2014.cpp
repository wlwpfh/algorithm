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
		// pop�ϰ�
		int min = pq.top();
		pq.pop();

		//�ٸ� ���� ������ ���ϱ� -> push�� ������ vector�� �ֱ�
		// -> index�� k�� ���� �̱�  

	}




	return 0;
}