#include<vector>
#include<stdio.h>
#include<queue>

#define INF 987654321

struct Data {
	int node;
	int weight;
	Data(int a, int b) {
		node = a;
		weight = b;
	}
	bool operator<(const Data d) const {
		return weight > d.weight;
	}
};

using namespace std;

vector<Data> v[10];
int dis[10];
bool isVisited[10];

priority_queue<Data> pq;

int N, M;

int main() {
	scanf("%d %d", &N, &M);
	int a, b, c;

	for (int i = 0; i <= N; i++) {
		v[i].clear();
		dis[i] = INF;
		isVisited[i] = false;
	} //���� �ʱ�ȭ

	for (int i = 0; i < M; i++) {

		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(Data(b, c));
		v[b].push_back(Data(a, c));
		//������̱� ������  
	}


	//���ͽ�Ʈ�� ����
	//�����Ϸ��� ��带 ���ϱ� - �ϴ� 1������ �ϱ� 

	dis[1] = 0;
	pq.push(Data(1, 0));

	while (!pq.empty()) {
		Data now = pq.top(); //���� �湮�� ���  
		pq.pop();

		if (isVisited[now.node])
			continue;

		isVisited[now.node] = true;

		for (int i = 0; i < v[now.node].size(); i++) {
			//���� �湮�� ��忡 ����� ����� ������ ����
			Data next = v[now.node].at(i);

			if (dis[next.node] > dis[now.node] + next.weight)
				//�� ~ �̰� INF���� �� �����ϱ� �� ª�� �Ÿ��� ����  
				dis[next.node] = dis[now.node] + next.weight;
			pq.push(Data(next.node, dis[next.node]));
			//���� ���� ���ŵ� �Ÿ��� �ֱ�  
		}

	}

	for (int i = 0; i <= N; i++) {
		printf("%d ", dis[i]);
	}



	return 0;
}