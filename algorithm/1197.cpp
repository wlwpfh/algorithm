#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int V, E;
long long sum = 0;
int parent[10001];

struct Node {
	int n;
	int m;
	int value;

	Node(int a, int b, int c) {
		n = a;
		m = b;
		value = c;
	}
	bool operator<(Node n) {
		return value < n.value;
	}
	//오름차순 정리  
};

int Find(int v) {
	if (v == parent[v])
		return v;
	else {
		return parent[v] = Find(parent[v]);
	}
}

void Union(int a, int b) {
	parent[Find(a)] = Find(b);
}

int main() {
	int i;
	int a, b, c;

	scanf("%d %d", &V, &E);

	for (i = 1; i <= V; i++) {
		parent[i] = i;
	}

	vector<Node> n;
	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		n.push_back(Node(a, b, c));
	}

	sort(n.begin(), n.end());

	int count = 0;

	for (i = 0; i < E; i++) {
		int n1 = Find(n[i].n);
		int n2 = Find(n[i].m);

		if (n1 != n2) {
			sum += n[i].value;
			Union(n[i].n, n[i].m);
		}
	}

	printf("%lld", sum);

	return 0;
}