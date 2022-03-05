#include<stdio.h>
#include<vector>
using namespace std;

int N;
Node n[1000];
int level[1000];
int
struct Node {
	int left;
	int right;
	Node(int b, int c) {

		left = b;
		right = c;
	}
};

void inOrder(int node) {
	if (node == -1)
		return;
	inOrder(n[node].left);
	inOrder(n[node].right);
}

int main() {

	scanf("%d", &N);

	int i, a, b, c;

	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &a, &b, &c);
		n[a].left = b;
		n[a].right = c;

	}

	return 0;
}