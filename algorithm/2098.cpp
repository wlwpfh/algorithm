#include <stdio.h>
#include <algorithm>
#define INF 987654321
#define MAX 16
using namespace std;

int N;
int map[MAX][MAX];
int dp[MAX][(1 << MAX)];

int maxBit;

int dfs(int n, int bit) {

    if (bit == maxBit) {
        if (map[n][0] == 0) return INF;
        return  map[n][0];
    }

    if (dp[n][bit] != INF) return dp[n][bit];

    for (int i = 0; i < N; i++) {
        if (map[n][i] == 0)
            continue;
        if ((bit & (1 << i)) > 0)
            continue;
        int nextBit = (bit | (1 << i));
        dp[n][bit] = min(dp[n][bit], dfs(i, nextBit) + map[n][i]);
    }

    return dp[n][bit];
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    maxBit = (1 << N) - 1;

    //printf("maxBit:%d",maxBit);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= maxBit; j++) {
            dp[i][j] = INF;
        }
    }

    printf("%d", dfs(0, 1));

    return 0;
}