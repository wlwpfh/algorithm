#include<iostream>
#include<vector>

using namespace std;

struct Node {
	char left; char right;

};

Node tree[27];

void preOrder(char node) { //���� ��ȸ 
	if (node == '.')
		return;
	printf("%c", node);
	preOrder(tree[node - 'A'].left);

	preOrder(tree[node - 'A'].right);
}

void postOrder(char node) { //���� ��ȸ  
	if (node == '.')
		return;
	postOrder(tree[node - 'A'].left);
	postOrder(tree[node - 'A'].right);
	printf("%c", node);
}

void inOrder(char node) { //���� ��ȸ  
	if (node == '.')
		return;
	inOrder(tree[node - 'A'].left);
	printf("%c", node);
	inOrder(tree[node - 'A'].right);
}

int main() {
	int n;
	char a, b, c;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf(" %c %c %c", &a, &b, &c);
		//tree[a-'A']=Node(a,b,c);
		tree[a - 'A'].left = b;
		tree[a - 'A'].right = c;
	}

	preOrder('A');
	printf("\n");
	inOrder('A');
	printf("\n");
	postOrder('A');

	return 0;
}