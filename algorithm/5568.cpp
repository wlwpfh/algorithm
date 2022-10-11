#include<stdio.h>
#include<map>
#include<string>
#include<vector>

using namespace std;

int n, k, answer;
int card[11];
map<string, int> m;
vector<int> v;
bool visited[11];

void backTracking(int count, string s) {
	if (count == k) {
		printf("현재의 s는 %s\n", s.c_str());
		m[s]++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;

			backTracking(count + 1, s + to_string(card[i]));
			visited[i] = false;

		}
	}

}

int main() {
	scanf("%d", &n);
	scanf("%d", &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}

	backTracking(0, "");

	printf("%d", m.size());

	return 0;
}