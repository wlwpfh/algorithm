#include<stdio.h>
#include<algorithm>  

using namespace std;
int n, m;
int tree[10000001];

bool findMax(int size) {
	long long h = 0;
	for (int i = 0; i < n; i++) {
		h += max(0, tree[i] - size);
		//경우에 따라서 tree[i]가 size보다 작은 경우가 있을 수 있으니까

	}
	if (h >= m)	return true;
	else 		return false;
}

// ub, lb - 
// lb - 1부터 ( 절단기의 시작인 0부터 ) 

int main() {

	int lb = 0, ub = 0, ans;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[i]);
		ub = max(ub, tree[i]);
	}

	while (lb + 1 < ub) {
		m = lb + (ub - lb) / 2;
		if (findMax(m)) lb = m;
		else ub = m;
	}

	printf("%d", lb);

	return 0;
}