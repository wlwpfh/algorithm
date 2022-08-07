#include<stdio.h>
#include<vector>

using namespace std;

int N, M;
//도시의 수 - 200이하  
//여행 계획에 속한 도시들의 수 - 1000이하   
int parent[200];
int arr[200][200];
vector<int> v;

int Find(int a) {
	if (parent[a] != a)
		return parent[a] = Find(parent[a]);
	return a;
}


int main() {
	int tmp;

	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);

			if (i != j && arr[i][j] == 1) {
				int x = Find(i);
				int y = Find(j);

				if (x < y)
					parent[y] = x;
				else
					parent[x] = y;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	bool travel = true;

	for (int i = 0; i < M - 1; i++) {
		int a = v[i];
		int b = v[i + 1];

		if (Find(a) != Find(b)) {
			travel = false;
			break;
		}
	}

	if (travel == false)
		printf("NO");
	else
		printf("YES");


	return 0;
}