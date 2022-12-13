#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int max_h = 0;
    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size(); i++) {
        max_h = citations.size() - i;

        if (max_h <= citations[i])
            break;
        if (citations[citations.size() - 1] == 0) {
            max_h = 0;
            break;
        }
    }
    return max_h;
}