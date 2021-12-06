#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	stack<int>s;

	int n, num, tmp;
	string str;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> str;
		fgetc(stdin);
		if (str == "push") {
			scanf("%d", &num);

			s.push(num);
		}
		else if (str == "pop") {
			if (s.empty()) printf("-1 \n");
			else {
				tmp = s.top();
				printf("%d \n", tmp);
				s.pop();
			}
		}
		else if (str == "size") {
			printf("%d \n", s.size());
		}
		else if (str == "empty") {
			if (s.empty()) printf("1 \n"); else printf("0 \n");
		}
		else if (str == "top") {
			if (s.empty()) printf("-1 \n"); else printf("%d \n", s.top());
		}
	}


	return 0;
}