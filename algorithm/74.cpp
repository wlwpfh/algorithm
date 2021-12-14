#include<stdio.h>
#include<queue>

using namespace std;

int main() {

	int n, top;
	priority_queue<int, vector<int>, greater<int> > pq;
	vector<int> v;
	while (1) {
		scanf("%d", &n);

		if (n == 0) {
			top = pq.top();
			//pq.pop();
			v.push_back(top);
		}
		else if (n == -1)
			break;

		else {
			pq.push(n);
		}


	}

	for (int i = 0; i < v.size(); i++)
		printf("%d \n", v[i]);


	return 0;
}