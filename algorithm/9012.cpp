#include<stdio.h>
#include<stack>
#include<cstring>
#define MAX_LEN 50

using namespace std;

char c[MAX_LEN + 1];
stack<char> s;
int main() {

	int i, test_case;

	bool right = false;
	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++) {

		int l_count = 0, r_count = 0;
		bool right = false;

		getchar();
		scanf("%s", &c);
		//printf("%c",c[0]);

		for (int j = 0; j < strlen(c); j++) {
			if (c[j] == '(')
				l_count++;
			else
				r_count++;
		}

		//printf("char: %s \n",c);

		//printf("l_count: %d, r_count:%d \n",l_count, r_count);

		s.push(c[i]);


		while (1) {
			if (s.size() == 0 || (l_count == 0 && r_count != 0) || (l_count != 0 && r_count == 0))
				break;
			if (s.top() == ')') {
				s.pop();
				right = true;
				r_count--;
			}
			if (s.top() == '(' || right == true) {
				s.pop();
				l_count--;
				right = false;
			}


		}

		if (s.size() == 0 && right == false)
			printf("YES \n");
		else
			printf("NO \n");

		while (!s.empty())
			s.pop();
		memset(c, 0, sizeof(c));
	}

	return 0;
}