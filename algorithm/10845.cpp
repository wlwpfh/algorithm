#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
	queue<int>q;

	int n, num, tmp;
	string str;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> str;
		fgetc(stdin);
		if (str == "push") {
			scanf("%d", &num);
			q.push(num);

		}
		else if (str == "pop") {
			if (q.empty()) printf("-1 \n");
			else {
				tmp = q.front();
				q.pop();
				printf("%d \n", tmp);
			}
		}
		else if (str == "size") {
			printf("%d \n", q.size());
		}
		else if (str == "empty") {
			if (q.empty()) printf("1 \n"); else printf("0 \n");
		}
		else if (str == "front") {
			if (q.empty()) printf("-1 \n"); else printf("%d \n", q.front());
		}
		else if (str == "back") {
			if (q.empty()) printf("-1 \n"); else printf("%d \n", q.back());
		}
	}


	return 0;
}