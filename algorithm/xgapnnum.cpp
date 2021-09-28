#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n);
    long i;
    for (i = 0; i < n; i++) {
        answer[i] = x * (i + 1);
    }
    return answer;
}