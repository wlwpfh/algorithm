#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int n, root = 0;
	priority_queue<int> pq;
	vector<int> v;
	scanf("%d", &n);

	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			root = pq.top();
			pq.pop();
			v.push_back(root);
		}
		if (n == -1)
			break;

		pq.push(n);
	}

	for (int i = 0; i < v.size(); i++) {
		printf("%d \n", v[i]);
	}

	//	for(int i=0;i<pq.size();i++){
	//		if(!pq.empty()){
	//			printf("%d ",pq.top());
	//			pq.pop();
	//		}
	//	}

	return 0;
}