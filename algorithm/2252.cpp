#include<stdio.h>
#include<queue>  
#include<vector>
#include<cstring> //memset을 위해서  
#define MAX_SIZE 32000
using namespace std;

int n, m;
int main() {
	scanf("%d %d", &n, &m);
	int students[n + 1] = { 0, };
	vector<int> v[MAX_SIZE];
	queue<int> answer;
	int a, b;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		//a가 b앞에 와야한다.
		// a -> b
		students[b]++;
		v[a].push_back(b);
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (students[i] == 0) {
			q.push(i);
			answer.push(i);
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i < v[x].size(); i++) {
			students[v[x][i]]--;

			if (students[v[x][i]] == 0) {
				q.push(v[x][i]);
				answer.push(v[x][i]);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		printf("%d ", answer.front());
		answer.pop();
	}

	return 0;
}