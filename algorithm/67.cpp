#include<stdio.h>
#include<vector>

using namespace std;

int cost, level, n, m;

vector<pair<int, int> >adlist[20];

void least_cost(int num) { //지금 현재 정점 
	if (num == level) {
		cost += adlist[num][3];
	}
	else {
		//다음 것 중에서 최소값이 무엇인지 
	}
}
int main() {
	scanf("%d %d", &n, &m);


	return 0;
}