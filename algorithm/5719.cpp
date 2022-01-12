#include<stdio.h>
#include<queue>
#include<vector>

#define MAX_SIZE 1000

using namespace std;

struct Node {
	int node;
	int weight;

	Node(int a, int b) {
		node = a;
		weight = b;
	}

	bool operator<(const Data d) const {
		return weight > d.weight;
	}
};

vector<Node> n(MAX_SIZE + 1);
priority_queue<Node> pq;
int dis[MAX_SIZE + 1];

int main() {


	return 0;
}