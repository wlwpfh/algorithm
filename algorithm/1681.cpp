#include<iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	int N, L, res = 0;
	init();

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		while (to_string(++res).find(L + '0') != string::npos)
			;
	}

	cout << res;

	return 0;
}