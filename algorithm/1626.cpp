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

//ũ�罺Į �̿��ϱ� 

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
	} // ������������ �� �־���

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

	if (count != V - 1) //���д� Ʈ���� �������� �ʴ� ��� 
		printf("-1");

	//�ι�°�� ���� ���д� Ʈ���� �������� �ʴ� ��� 

	//�ι�°�� ���� ���д� Ʈ���� ��� ������  

	return 0;

}