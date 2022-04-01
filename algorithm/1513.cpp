#include<stdio.h>
#include<cstring> 
using namespace std;

int N, M, C;
int map[51][51];
int dp[51][51][51][51];
// 	  x  y    l   k
// (x,y)���� (n,m)���� �� �� l�� ������ ���, �������� k�� �������� ���  

int dfs(int x, int y, int prev, int count) {
	//���� ��ġ  , ���������� �鸰 ������ -prev, �� �鸰 ������ count

	if (x<0 || y<0 || x>N || y>M)
		return 0;

	int now = dp[x][y][count][prev];

	if (now != -1) //�̹� �Դ� �� ���  
		return now;



}

int main() {
	// N * M�� ����, ���� 1,1 �п��� N,M�� �ְ� �������� C�� 
	//�̵� �� ���� ��ġ���� ������ ���ų� ���������� ���� ���
	// ������ ��ȣ�� �����ϴ� ����� ���� ��. 0-> 0 , 0->1, 0->1, 0->1->2
	//�������� k�� �湮�ؼ� �п��� �����ϴ� ����� �� 
	//������ 0�� �湮 ~ C �� �湮�� ����� ��  
	scanf("%d %d %d", &N, &M, &C);

	int i, tmp_x, tmp_y;

	for (i = 1; i <= C; i++) {
		scanf("%d %d", &tmp_x, &tmp_y);
		map[tmp_x][tmp_y] = i;
	} //����� ���ڷ� ������.  

	memset(dp, -1, sizeof(dp));
	//dp�迭 �ʱ�ȭ


	for (i = 0; i <= C; i++)
		printf("%d ", dfs(1, 1, 0, i));
	//0�� ���� ��쵵 �֤��ϱ�  

	return 0;
}