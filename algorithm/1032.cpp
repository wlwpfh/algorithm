#include<iostream>
#include<string>
using namespace std;

int main() {
	string answer = "";
	int n;
	string tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> tmp;

		if (answer == "")
			answer = tmp;
		else {
			for (int j = 0; j < answer.length(); j++) {
				if (tmp[j] != answer[j]) {

					answer[j] = '?';
				}
			
			}
			
	}
	printf("%s \n", answer.c_str());
	return 0;
}