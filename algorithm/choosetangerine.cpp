#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;

    for (int i = 0; i < tangerine.size(); i++)
        m[tangerine[i]]++;

    vector<int> tmp;

    for (auto a : m) {
        tmp.push_back(a.second);
    }
    sort(tmp.begin(), tmp.end(), greater<int>());

    for (int i = 0; i < tmp.size(); i++) {
        if (k <= 0)
            break;
        k -= tmp[i];
        answer++;
    }
    return answer;
}