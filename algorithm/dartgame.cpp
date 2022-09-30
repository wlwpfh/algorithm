#include <string>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

map<char, int>m;

void init() {
    m['S'] = 1;
    m['D'] = 2;
    m['T'] = 3;
}
vector<int> v;
int solution(string dartResult) {
    int i, answer = 0, curr = 0;

    init();
    for (i = 0; i < dartResult.length(); i++) {
        if (dartResult[i] >= '0' && dartResult[i] <= '9') {

            v.push_back(curr);

            if (dartResult[i + 1] == '0') {
                curr = 10;
                i++;
            }
            else
                curr = dartResult[i] - '0';
            continue;
        }
        if (m[dartResult[i]] != 0) {
            curr = pow(curr, m[dartResult[i]]);
            continue;
        }
        if (dartResult[i] == '*') {
            if (i == 2)
                curr *= 2;
            else {
                curr *= 2;
                v[v.size() - 1] *= 2;
            }
        }
        if (dartResult[i] == '#')
            curr = -curr;
    }
    v.push_back(curr);

    for (i = 0; i < v.size(); i++) {
        printf("%d + ", v[i]);
        answer += v[i];
    }
    printf("= %d \n", answer);
    return answer;
}