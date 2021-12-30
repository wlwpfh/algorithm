#include<stdio.h>

using namespace std;
int n, m;

// 1. 상태 공간 트리의 깊이 우선 검색을 실시
// 2. 각 노드가 유망한지를 점검한다. 
// 3. 해당 노드가 유망하지 않다면 부모로 돌아가서 검색을 계속한다. 

void backTracking(int start, int count) {
	//현재의 시작점, 내가 센 것의 개수 
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