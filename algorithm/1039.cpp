// 큐 안에 같은 수가 없도록  
//bfs
#include<stdio.h>
#include<queue>
#include<set>
#include<string>
using namespace std;

int k;
int n;
queue<string> q;
set<string> sets;
char t;

void bfs(int count) {
	while (count != k) {
		string s = q.front();
		q.pop();
		//string s=to_string(number);

		for (int j = 0; j < s.length(); j++) {
			for (int i = 0; i < j; i++) {
				if ((i == 0 && s[j] == '0') || (j == 0 && s[i] == '0'))
					continue;

				t = s[i];
				s[i] = s[j];
				s[j] = t;
				//number=stoi(s);
				if (sets.count(s) != 0) {
					continue;
				}

				count++;
				q.push(s);
			}
		}
	}
}


int main() {
	scanf("%d %d", &n, &k);
	string s = to_string(n);
	q.push(s);

	bfs(0);
	string max = 0;

	while (!q.empty()) {
		if (max < q.front())
			max = q.front();
		q.pop();
	}

	return 0;
}