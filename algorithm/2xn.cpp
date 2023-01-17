#include <string>
#include <vector>
#define DIV 1000000007
using namespace std;

int dp[600001] = { 0, };

int solution(int n) {
    int answer = 0;
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        dp[i] = (dp[i - 1] + dp[i - 2]) % DIV;
    }
    return dp[n];
}