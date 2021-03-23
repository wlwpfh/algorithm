#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;
int main54_() {

	stack<char> s;

	char a[50];
	int i, flag = 1;

	scanf("%s", &a);
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == '(')
			s.push(a[i]);
		else {
			if (s.empty()) { //비어있으니까 
				printf("NO");
				flag = 0;
				break;
			}
			else {
				s.pop();
			}
		}
	}
	if (s.empty() && flag == 1)
		printf("YES");
	else if (!s.empty() && flag == 1)
		printf("NO");
	return 0;
}