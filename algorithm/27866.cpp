#include<iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();

	string s;
	int i;
	cin >> s >> i;

	cout << s[i - 1];

	return 0;
}