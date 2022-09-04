#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int area = brown + yellow;
    int row;
    for (int col = 3; col <= area / 2; col++) {
        if (area % col != 0)
            continue;
        row = area / col;

        if ((col - 2) * (row - 2) == yellow) {
            answer.push_back(row);
            answer.push_back(col);
            break;
        }
    }

    return answer;
}