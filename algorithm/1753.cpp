#include<stdio.h>
#include<vector>
using namespace std;

struct Node {
	int c1;
	int c2;
	int weight;

	Node(int a, int b, int c) {
		c1 = a;
		c2 = b;
		weight = c;
	}
};

int v, e, k;
vector<Node> city;

int main() {
	int a, b, c;

	scanf("%d %d", &v, &e);
	scanf("%d", &k);

	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		city.push_back(Node(a, b, c));
	}
	//¾ç¹æÇâ X

}