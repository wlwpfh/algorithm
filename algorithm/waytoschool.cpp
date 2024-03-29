#include <vector>

#define DIV 1000000007
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int i, j, answer = 0;

    vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));

    map[1][1] = 1;

    for (i = 0; i < puddles.size(); i++) {
        map[puddles[i][1]][puddles[i][0]] = -1;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (map[i][j] == -1)
                continue;
            if (map[i - 1][j] != -1)
                map[i][j] += map[i - 1][j];
            if (map[i][j - 1] != -1)
                map[i][j] += map[i][j - 1];

            map[i][j] %= DIV;
        }
    }

    return map[n][m];

}