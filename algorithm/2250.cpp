#include<stdio.h>
#include<vector>
using namespace std;

struct Node {
	int left;
	int right;

};

int N;
Node Nodes[10002];
vector<int> width;
vector<int> height;
int roots[10002] = { 0, };

void inOrder(int node, int level) {

	if (node == -1 || node > N)
		return;

	inOrder(Nodes[node].left, level + 1);
	//printf("%d ",node);
	width.push_back(node);
	height.push_back(level);
	inOrder(Nodes[node].right, level + 1);
}

int main() {

	scanf("%d", &N);
	int max_width = 1, max_level = 1;
	int i, j, a, b, c;
	int start;
	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &a, &b, &c);

		Nodes[a].left = b;
		Nodes[a].right = c;

		if (b != -1)
			roots[b]++;
		if (c != -1)
			roots[c]++;

		roots[a]++;
	}

	for (i = 1; i <= N; i++) {
		if (roots[i] == 1) { //루트 노드는 한번만 나오니까 
			start = i;
			break;
		}
	}
	//printf("start: %d \n",start);
	inOrder(start, 0);
	//넓이, 높이 다 0부터 시작함. 둘 다 나중에 +1해주기  

	for (i = 0; i < width.size(); i++) {
		if (height[i] + 1 > max_level)
			max_level = height[i] + 1;
		if (i + 1 > max_width)
			max_width = i + 1;
	}

	int arr[max_level + 1][max_width + 1] = { 0, };

	for (i = 0; i < width.size(); i++) {
		//printf("height:%d, width:%d, 숫자:%d \n",height[i],i,width[i]);
		arr[height[i] + 1][i + 1] = width[i];


	}

	//printf("max_height:%d, max_width:%d \n",max_level,max_width);

	int ans_1 = 0, ans_2 = 0;
	for (i = 1; i <= max_level; i++) {
		a = b = 0;
		for (j = 1; j <= max_width; j++) {
			//일단 a가 시작 width
			//b가 끝나는  width 
			//i가 현재의 level
			//저장은 ans_1, ans_2;
			if (a == 0 && arr[i][j] != 0)
				a = j;
			if (a != 0 && arr[i][j] != 0)
				b = j;

		}

		if (b - a >= ans_1) {
			ans_1 = b - a + 1;
			ans_2 = i;
		} //업데이트  
	}

	printf("%d %d", ans_2, ans_1);

	return 0;
}