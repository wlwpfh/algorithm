#include <vector>
#include <algorithm>
using namespace std;

int bud = 0;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());

    for (int i = 0; i < d.size(); i++) {
        if (d[i] + bud <= budget) {
            answer++;
            bud += d[i];
        }

    }

    return answer;
}