#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m;
int tree[1000000];

bool findMax(int size) {
	long long h = 0;
	for (int i = 0; i < n; i++) {
		h += max(0, tree[i] - size);
		//경우에 따라서 tree[i]가 size보다 작은 경우가 있을 수 있으니까	 
	}
	if (h >= m)	return true;
	else 		return false;
}

int main() {

	int lb = 0, ub = 0;

	scanf("%d %d", &n, &m);
	int mid;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[i]);
		ub = max(ub, tree[i]);
	}

	while (lb + 1 < ub) {
		mid = lb + (ub - lb) / 2;
		if (findMax(mid)) lb = mid;
		else ub = mid;
	}

	printf("%d", lb);

	return 0;
}