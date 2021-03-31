#include<stdio.h>
void postorder(int num) { //후위순회 
	if (num > 7)
		return;
	else {
		postorder(num * 2);
		postorder(num * 2 + 1);
		printf("%d ", num);
	}

}
void preorder(int num) { //후위순회 
	if (num > 7)
		return;
	else {
		printf("%d ", num);
		preorder(num * 2);
		preorder(num * 2 + 1);

	}
}
void inorder(int num) {
	if (num > 7)
		return;
	else {
		inorder(num * 2);
		printf("%d ", num);
		inorder(num * 2 + 1);

	}


}
int main58_() {
	printf("전위순회 출력: ");
	preorder(1);
	printf("\n");
	printf("중위순회 출력: ");
	inorder(1);
	printf("\n");
	printf("후위순회 출력: ");
	postorder(1);


	return 0;
}