#include <string>
#include <vector>
#define DIV 1234567
using na#include <string>
#include <vector>
#define DIV 1234567
using namespace std;
vector<int> count;
void longJump(int n, int curr) {
    if (n < curr)
        return;
    if (n - curr >= 3 && curr > 3) {
        long long tmp = (count[curr - 2] + count[curr - 1]) % DIV;
        count.push_back(tmp);
    }
    longJump(n, curr + 1);
}

long long solution(int n) {

    int answer = 0;

    count.push_back(1); //1
    count.push_back(2); //2
    count.push_back(3); //3

    longJump(n, 0);

    return count[n];
}