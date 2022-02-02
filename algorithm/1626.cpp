#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX_V 50000

using namespace std;

struct Node {
	int s, e, value;
	Node(int a, int b, int c) {
		s = a;
		e = b;
		value = c;
	}
	bool operator<(const Node n)const {
		return value < n.value;
	}
};

int V, E;
int parent[MAX_V + 1];
vector<Node> node;
long long sum;

//크루스칼 이용하기 

int Find(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = Find(parent[v]);
}

void Union(int a, int b) {
	parent[Find(a)] = Find(b);
}

int main() {
	int i, count = 0;
	int a, b, c;
	scanf("%d %d", &V, &E);

	for (i = 1; i <= V; i++)
		parent[i] = i;

	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);

		node.push_back(Node(a, b, c));
	} // 오름차순으로 잘 넣었음

	sort(node.begin(), node.end());


	for (i = 0; i < E; i++) {
		int n = node[i].s;
		int m = node[i].e;
		int value = node[i].value;

		if (Find(n) != Find(m)) {
			Union(n, m);
			sum += value;
			count++;
		}
	}

	if (count != V - 1) //스패닝 트리가 존재하지 않는 경우 
		printf("-1");

	//두번째로 작은 스패닝 트리가 존재하지 않는 경우 

	//두번째로 작은 스패닝 트리는 어떻게 만들지  

	return 0;

}