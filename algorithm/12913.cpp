#include <algorithm>
#include <vector>
using namespace std;

int Max(vector<int> cols, int index) {
    int max = 0;
    for (int i = 0; i < 4; i++) {
        if (index == i)
            continue;
        if (cols[i] > max)
            max = cols[i];
    }
    return max;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>> dp = land;

    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j] += Max(dp[i - 1], j);
            answer = max(dp[i][j], answer);
        }
    }

    return answer;
}