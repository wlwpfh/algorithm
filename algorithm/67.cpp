#include<stdio.h>
#include<vector>

using namespace std;

int cost, level, n, m;

vector<pair<int, int> >adlist[20];

void least_cost(int num) { //���� ���� ���� 
	if (num == level) {
		cost += adlist[num][3];
	}
	else {
		//���� �� �߿��� �ּҰ��� �������� 
	}
}
int main() {
	scanf("%d %d", &n, &m);


	return 0;
}