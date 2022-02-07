#include<stdio.h>
#include<string.h>
using namespace std;

int n, m;

bool visit[10] = { 0, };
int arr[10] = { 0, };
void backTracking(int num, int count) {
	//���� ����, �ش� ���� ����
	int i;
	if (count == m) {
		for (i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		visit[arr[m - 1]] = false;
		return;
	}

	for (i = num; i <= n; i++) {
		if (visit[i] == false) {
			//visit[i]=true;
			arr[count] = i;
			if (count != m)
				backTracking(i, count + 1);
			else
				backTracking(i + 1, count + 1);
			visit[i] = false;
		}
	}
}
//�ߺ� ��� -> �ش� ������ŭ �ޱ�  

int main() {

	scanf("%d %d", &n, &m);


	backTracking(1, 0);


	//�������� ����, �ߺ� X  

	return 0;
}