#include<stdio.h>

using namespace std;
int n, m;

// 1. ���� ���� Ʈ���� ���� �켱 �˻��� �ǽ�
// 2. �� ��尡 ���������� �����Ѵ�. 
// 3. �ش� ��尡 �������� �ʴٸ� �θ�� ���ư��� �˻��� ����Ѵ�. 

void backTracking(int start, int count) {
	//������ ������, ���� �� ���� ���� 
	for (int i = count; i <= m; i++) {
		backTracking(start + 1, count + 1);
		printf("%d ", start);
	}
	if (start == n && count == m)
		return;

}

int main() {

	scanf("%d %d", &n, &m);

	backTracking(1, 1);

	return 0;
}