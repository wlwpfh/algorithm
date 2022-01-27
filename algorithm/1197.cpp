#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int V, E;
long long sum = 0;
int friends[10001];

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
};

int Find(int v) {
	if (v == friends[v])
		return v;
	else {
		return friends[v] = Find(friends[v]);
	}
}

void Union(int a, int b) {
	friends[Find(a)] = Find(b);
}

int main() {
	int i;
	int a, b, c;

	scanf("%d %d", &V, &E);

	for (i = 1; i <= V; i++) {
		friends[i] = i;
	}

	vector<Node> n;
	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		n.push_back(Node(a, b, c));
	}

	sort(n.begin(), n.end());


	for (i = 0; i < V; i++) {
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