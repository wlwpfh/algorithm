#include<stdio.h>
#include<algorithm>  

using namespace std;
int n, m;
int tree[10000001];

bool findMax(int size) {
	long long h = 0;
	for (int i = 0; i < n; i++) {
		h += max(0, tree[i] - size);
		//��쿡 ���� tree[i]�� size���� ���� ��찡 ���� �� �����ϱ�

	}
	if (h >= m)	return true;
	else 		return false;
}

// ub, lb - 
// lb - 1���� ( ���ܱ��� ������ 0���� ) 

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