#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (s / n <= 0) {
        answer.push_back(-1);
        return answer;
    }

    for (int i = n; i > 0; i--) {
        int tmp = s / i;
        s -= tmp;

        answer.push_back(tmp);
    }

    return answer;
}