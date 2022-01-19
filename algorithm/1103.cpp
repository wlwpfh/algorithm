#include<stdio.h>
#include<algorithm>
using namespace std;

int N, M, Ans;
int dp[55][55] = { 0, }; //��� �ߺ��� ���� ���ؼ�  
char map[55][55] = { 0, }; //������ �����ϱ� ���ؼ�  
bool visited[55][55]; // ������ �Ȱ����� üũ�ϱ� ���ؼ�  
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool go(int r, int c, int cnt)
{
    //���ѹ� ������ �� �ִ� ���
    if (Ans == -1) return true;

    Ans = max(Ans, cnt);

    visited[r][c] = true;
    //DP���̺� ��� ����� update�Ͽ� �� ���� �Ѱ��� ���� ���̶�� ������� �ʵ��� �Ѵ�.
    dp[r][c] = cnt;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dx[i] * (map[r][c] - '0');//���ڿ��� �� ���ڿ��� '0' ���ڸ� ���� int�� �ȴ�.(ASCII�ڵ�)
        int nc = c + dy[i] * (map[r][c] - '0');

        //��Ʈ���� ������ ����ų� �����ΰ��� ������ ����ǹǷ� Ž���� �������� �ʴ´�.
        if (nr < 0 || nr >= N || nc < 0 || nc >= M || map[nr][nc] == 'H') continue;

        //�湮�� ���� �� �湮�Ϸ� �Ѵٸ� ���ѹ� ������ �� �ִٴ� �ǹ�
        if (visited[nr][nc])
        {
            Ans = -1;
            return true;
        }

        //�̹� ���� ���� DP���̺� ��ϵǸ� DP�� ���� cnt���� ũ�ٸ� 
        //�̹� �� ��� �����̴� ���� ���Ǿ� �ִ�.
        if (dp[nr][nc] > 0 && cnt < dp[nr][nc]) continue;

        //���ѹ� ������ �� �ִٸ� dfs���� true�� return�ȴ�
        if (go(nr, nc, cnt + 1)) return true;
    }

    //���ƿͼ��� Visit Flag�� false�� ����
    visited[r][c] = false;
    return false;
}

int main() {

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", &map[i]);

    }

    go(0, 0, 1);

    printf("%d", Ans);

    return 0;
}
