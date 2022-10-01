#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int i, j, answer = 0, tmp = 0;

    for (i = 0; i < lost.size(); i++) {
        for (j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i -= 1;
            }
        }
    }
    answer = n - lost.size();

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (i = 0; i < lost.size(); i++) {
        for (j = 0; j < reserve.size(); j++) {
            if (abs(lost[i] - reserve[j]) == 1) {
                reserve.erase(reserve.begin() + j);
                answer++;
            }
        }
    }
    return answer;
}
//만약 lost와 reserve에 둘 다 같은 아이가 있으면 양쪽을 소거해야 함.