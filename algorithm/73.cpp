#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int n, root = 0;
	priority_queue<int, vector<int> > pq;
	vector<int> v;
	//scanf("%d",&n);

	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			root = pq.top();
			pq.pop();
			v.push_back(root);
		}
		else if (n == -1)
			break;
		else
			pq.push(n);
	}

	for (int i = 0; i < v.size(); i++) {
		printf("%d \n", v[i]);
	}



	return 0;
}