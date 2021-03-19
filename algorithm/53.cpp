#include<stdio.h>
#include<string>

#define SIZE 10

char stack[SIZE] = { 0, };
int top = -1;

bool isFull() { //스택이 포화상태인지 검사
	if (top >= SIZE - 1) {
		return true;
	}
	else
		return false;
}
bool isEmpty() { //스택이 공백상태인지 검사
	if (top == -1) {
		return true;
	}
	else
		return false;
}

void push(char data) {
	if (!isFull()) {
		top++; //미리 더해준 뒤 - 처음엔 -1이니까 0번쩨 배열에 넣어야 함.
		stack[top] = data;
	}
}
void pop() {
	if (!isEmpty()) {
		char tmp = stack[top];
		top--;
		//return tmp;
	}
	else {

	}
}

void printStack(int m) { //스택 원소 출력
	if (!isEmpty()) {
		if (m == 2) {
			for (int i = top; i >= 0; i--)
				printf("%d", stack[i]);
		}
		else if (m == 8) {
			for (int i = top; i >= 0; i--)
				printf("%o", stack[i]);
		}
		else {
			for (int i = top; i >= 0; i--)
				printf("%X", stack[i]);
		}
	}
	else {

	}
}
int main53_() {
	int n, res, i, m;


	scanf("%d %d", &n, &m);

	i = 0;
	while (1) {
		res = n % m;
		push(res);
		i++;
		n = n / m;

		if (n < m) {
			push(n);
			break;
		}
	}

	printStack(m);

	return 0;
}