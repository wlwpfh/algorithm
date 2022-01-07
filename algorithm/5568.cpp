#include<stdio.h>
#include<unordered_map>
#include<string>

using namespace std;

int n, k;
int card[11];

int main() {
	scanf("%d", &n);
	scanf("%d", &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}

	string tmp;

	unordered_map<string, int> um;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				tmp = to_string(card[i]) + to_string(card[j]);
				um[tmp]++;
			}
		}
	}

	printf("%d", um.size());

	return 0;
}