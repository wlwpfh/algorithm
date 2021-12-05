#include<iostream>
#include<algorithm>

using namespace std;

bool comp(char c1, char c2) {
	return c1 > c2;
}

int main() {

	string s;
	cin >> s;

	sort(s.begin(), s.end(), comp);

	printf("%s ", s.c_str());

	return 0;
}