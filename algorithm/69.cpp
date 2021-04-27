#include<stdio.h>
#include<vector>

using namespace std;

int main() {
	int i, a, b;
	vector<int> tree[8];

	for (i = 1; i <= 7; i++) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}


	return 0;
}