#include<stdio.h>

using namespace std;

int sets[1000001];

int Find(int num) {
	if (num == sets[num])
		return num;
	else
		return sets[num] = Find(sets[num]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a != b) sets[a] = b;
}

int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		sets[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0) {
			//친구에 넣고  
			Union(b, c);
		}
		else { //a가 1이라면 
		   //친구인지 출력하고 ~  
			b = Find(b);
			c = Find(c);
			if (b == c)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}