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
	}//내림차순 
};
vector<Node> cost;

int Find(int num) {
	if (num == parent[num])
		return num;
	else
		return parent[num] = Find(parent[num]);
}
void Union(int a, int b) {
	//root가 넘어옴
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
	//root을 자기 자신으로 설정, costSize는 1  

	for (i = 0; i < cost.size(); i++) {
		int x = Find(cost[i].a);
		int y = Find(cost[i].b);
		int w = cost[i].weight;

		if (x != y) {
			//둘이 한 그룹이 아닌 경우
			result += (costSize[x] * costSize[y] % MOD) * sum % MOD;
			result %= MOD;
			//printf("result:%d sum:%d \n",result,sum);
			Union(x, y);
		}
		sum -= w;
		//연결된 가중치는 빼주기  
	}

	printf("%lld", result % MOD);

	return 0;
}