#include<stdio.h>
#include<queue> 
#define MAX_SIZE 100
using namespace std;

// prim - ������ ������ �����ؼ� ���� ���¸� ���� Ʈ���� Ȯ���ϴ� ��
int v, e;
int checked[MAX_SIZE + 1];

struct Node {
	int dest;
	int weight;

	Node(int a, int b) {
		dest = a;
		weight = b;
	}

	bool operator<(const Node& n)const {
		return weight > n.weight;
	}
};

vector<pair<int, int>> city[MAX_SIZE];
queue<Node> q;
int main() {
	int a, b, c, res = 0;
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		city[a].push_back(make_pair(b, c));
		city[b].push_back(make_pair(a, c));
	}

	q.push(Node(1, 0)); //1���� �����ϱ� ������

	while (!q.empty()) {
		Node front = q.front();
		q.pop();
		int e = front.dest;
		int w = front.weight;

		if (checked[e] == 0) {
			//Ž������ ���� ���� 
			res += w;
			checked[e] = 1;

			for (int i = 0; i < city[e].size(); i++) {
				if (checked[city[e][i].first] == 0) {
					q.push(Node(city[e][i].first, city[e][i].second));

				}
			}
		}
	}

	printf("%d", res);

	return 0;
}