#include<stdio.h>
#include<algorithm>
using namespace std;

int N, M, Ans;
int dp[55][55] = { 0, }; //계산 중복을 막기 위해서  
char map[55][55] = { 0, }; //지도를 저장하기 위해서  
bool visited[55][55]; // 갔는지 안갔는지 체크하기 위해서  
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool go(int r, int c, int cnt)
{
    //무한번 움직일 수 있는 경우
    if (Ans == -1) return true;

    Ans = max(Ans, cnt);

    visited[r][c] = true;
    //DP테이블에 계산 결과를 update하여 더 유리 한것이 계산된 것이라면 계산하지 않도록 한다.
    dp[r][c] = cnt;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dx[i] * (map[r][c] - '0');//문자열로 된 숫자에서 '0' 문자를 빼면 int가 된다.(ASCII코드)
        int nc = c + dy[i] * (map[r][c] - '0');

        //매트릭스 범위를 벗어나거나 구멍인것은 게임이 종료되므로 탐색을 진행하지 않는다.
        if (nr < 0 || nr >= N || nc < 0 || nc >= M || map[nr][nc] == 'H') continue;

        //방문한 곳에 또 방문하려 한다면 무한번 움직일 수 있다는 의미
        if (visited[nr][nc])
        {
            Ans = -1;
            return true;
        }

        //이미 계산된 것은 DP테이블에 기록되며 DP의 값이 cnt보다 크다면 
        //이미 더 길게 움직이는 것이 계산되어 있다.
        if (dp[nr][nc] > 0 && cnt < dp[nr][nc]) continue;

        //무한번 움직일 수 있다면 dfs에서 true가 return된다
        if (go(nr, nc, cnt + 1)) return true;
    }

    //돌아와서는 Visit Flag를 false로 설정
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
