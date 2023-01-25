#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(B.begin(), B.end());
    sort(A.begin(), A.end());
    int index = 0;
    for (int i = 0; i < B.size(); i++) {
        if (A[index] < B[i]) {
            answer++;
            index++;
        }
    }

    return answer;
}