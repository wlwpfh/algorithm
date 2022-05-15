#include<stdio.h>
#include<vector>
#include<algorithm>
#define MOD 1000000000

using namespace std;

int N, M;
int parent[100001];
long long costSize[100001];
struct Node {
	int a;
	int b;
	int weight;

	Node(int x, int y, int z) {
		a = x;
		b = y;
		weight = z;
	}
	bool operator<(Node n) {
		return weight > n.weight;
	}//�������� 
};
vector<Node> cost;

int Find(int num) {
	if (num == parent[num])
		return num;
	else
		return parent[num] = Find(parent[num]);
}
void Union(int a, int b) {
	//root�� �Ѿ��
	costSize[a] += costSize[b];
	costSize[b] = 1;
	parent[b] = a;
}
int main() {

	int i, a, b, c;
	long long sum = 0, result = 0;

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		cost.push_back(Node(a, b, c));
		sum += c;
	}

	sort(cost.begin(), cost.end());

	for (i = 0; i <= N; i++) {
		parent[i] = i;
		costSize[i] = 1;
	}
	//root�� �ڱ� �ڽ����� ����, costSize�� 1  

	for (i = 0; i < cost.size(); i++) {
		int x = Find(cost[i].a);
		int y = Find(cost[i].b);
		int w = cost[i].weight;

		if (x != y) {
			//���� �� �׷��� �ƴ� ���
			result += (costSize[x] * costSize[y] % MOD) * sum % MOD;
			result %= MOD;
			//printf("result:%d sum:%d \n",result,sum);
			Union(x, y);
		}
		sum -= w;
		//����� ����ġ�� ���ֱ�  
	}

	printf("%lld", result % MOD);

	return 0;
}