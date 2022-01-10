#include<stdio.h>
#include<queue>
using namespace std;

struct Node {
	int s;
	int e;
	int weight;

	Node(int a, int b, int c) {
		s = a;
		e = b;
		weight = c;
	}
	bool operator<(const Node& n)const {
		return weight > n.weight;
	}
};

int n, m;
int parent[1001];

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
	int a, b, c, answer = 0;;
	priority_queue<Node> pq;
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		pq.push(Node(a, b, c));
	}

	int count = 0; //간선 연결 개수 세기  

	while (1) {
		if (count == n - 1)
			break;
		//연결된 노드의 간선 개수는 node의 개수-1이니까  
		Node node = pq.top();
		pq.pop();
		
		if (Find(node.s) != Find(node.e)) {
			Union(node.s, node.e);
			count++;
			answer += node.weight;
		}
	}
	printf("%d", answer);

	return 0;
}