#include<stdio.h>

using namespace std;

int friends[1001];

int Find(int v) { //v라는 학생이 속한 집합의 번호를 출력 
	if (v == friends[v])
		return v;
	else
		return friends[v] = Find(friends[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b)	friends[a] = b;
}

int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		friends[i] = i; //자신의 인덱스에 자신의 수가 들어가게 
	}

	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		Union(a, b);
	}
	scanf("%d %d", &a, &b);
	a = Find(a);
	b = Find(b);

	if (a == b) printf("YES");
	else printf("NO");

	return 0;
}