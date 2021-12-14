#include<vector>
#include<iostream>

using namespace std;

int n, res = 0;
int t[20], p[20];

void DFS(int L, int sum) { //��¥�� �׿� ���� ����  
	if (L == n + 1) {
		if (sum > res)
			res = sum; //������ ������ ���ͺ��� ū ���
	}
	else {
		if (L + t[L] <= n + 1) { //���翡 ��� �Ⱓ�� �־���  
			DFS(L + t[L], sum + p[L]); //�Ѵ� 
		}
		DFS(L + 1, sum); //���Ѵ�.  
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	int i;
	int a, b;
	scanf("%d", &n);


	for (i = 1; i <= n; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}

	DFS(1, 0);

	printf("%d", res);

	return 0;
}