#include <vector>
#include <iostream>
#define INF 987654321

using namespace std;

int Min(int a, int b) {
    return a < b ? a : b;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> v(rows, vector<int>(columns));
    int num = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++) {
            v[i][j] = num;
            num++;
        }

    for (int a = 0; a < queries.size(); a++) {

        int c = queries[a][1] - 1;
        int next_c = queries[a][3] - 1;
        int r = queries[a][0] - 1;
        int next_r = queries[a][2] - 1;

        int tmp = v[r][c];
        int ans = v[r][c];
        for (int i = r; i < next_r; i++) {
            v[i][c] = v[i + 1][c];
            ans = Min(ans, v[i][c]);
        }
        for (int i = c; i < next_c; i++) {
            v[next_r][i] = v[next_r][i + 1];
            ans = Min(ans, v[next_r][i]);
        }

        for (int i = next_r; i > r; i--) {
            v[i][next_c] = v[i - 1][next_c];
            ans = Min(ans, v[i][next_c]);
        }

        for (int i = next_c; i > c; i--) {
            v[r][i] = v[r][i - 1];
            ans = Min(ans, v[r][i]);
        }
        v[r][c + 1] = tmp;

        answer.push_back(ans);
    }
    return answer;
}