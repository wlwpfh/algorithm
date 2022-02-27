#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

priority_queue <int, vector<int>, greater<int> > pq;
int tmp;
int checked[542]; //�ߺ����� ���� ���� �����ϱ� ���ؼ�  
int main() {
	int i, K, N, tmp;

	scanf("%d %d", &K, &N);

	for (i = 0; i < K; i++) {
		scanf("%d", &tmp);
		pq.push(tmp);
		checked[tmp] = 1;
	}

	while (pq.size() != N) {
		//��� ���ϵ� ��.. 
		// �ڱ� �ڽ��� ���ص� �ȴ�! 
		int top_1 = pq.top();
		pq.pop();
		int top_2 = pq.top();

		tmp = top_1 * top_2;

		if (checked[tmp] == 0) {
			pq.push(tmp);
			checked[tmp] = 1;
		}
		pq.push(top_1);
	}



	return 0;
}