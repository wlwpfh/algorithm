#include<iostream>
#include<map>

using namespace std;

int dic[26];
int N;
string target, s;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {

	init();

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;

		cout << s[0] << s[s.length() - 1] << "\n";
	}


	return 0;
}