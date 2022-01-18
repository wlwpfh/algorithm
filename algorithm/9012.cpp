#include<stdio.h>
#include<stack>
#include<cstring>
#define MAX_LEN 50

using namespace std;

char c[MAX_LEN + 1];
stack<char> s;
int main() {

	int i, test_case;

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++) {

		int l_count = 0, r_count = 0;
		int r_pop = 0;
		bool isAns = false;
		getchar();
		scanf("%s", &c);
		//printf("%c",c[0]);

		for (int j = 0; j < strlen(c); j++) {
			if (c[j] == '(')
				l_count++;
			else
				r_count++;

			s.push(c[j]);
		}



		if (l_count == r_count) {
			//YES가 나올 가능성이 있음  
			while (1) {
				if (s.size() == 0) {
					isAns = true;
					break;
				}
				if (s.top() == '(' && r_pop == 0) {
					//printf("(를 뽑는데 이전에 )가 없었음 \n");
					break;
				}
				else if (s.top() == '(' && r_pop > 0) {
					r_pop--;
					s.pop();
					//printf("(를 뽑는데 이전에 )가 있음 \n");
				}
				else if (s.top() == ')') {
					r_pop++;
					s.pop();
				}
				//printf(")를 뽑았고 r_pop:%d \n",r_pop); 

			}

		}

		if (isAns == true)
			printf("YES \n");
		else
			printf("NO \n");

		while (!s.empty())
			s.pop();

		memset(c, 0, 50);
	}

	return 0;
}