#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<int> answer(2);
void recursive(int x, int y, int number) {
    int start = v[x][y];

    for (int i = x; i < x + number; i++) {
        for (int j = y; j < y + number; j++) {
            if (start != v[i][j]) {
                start = -1;
                break;
            }
        }
        if (start == -1)
            break;
    }

    if (start == -1) {
        recursive(x, y, number / 2);
        recursive(x, y + number / 2, number / 2);
        recursive(x + number / 2, y, number / 2);
        recursive(x + number / 2, y + number / 2, number / 2);
    }
    else if (start == 0)
        answer[0]++;
    else
        answer[1]++;

}

vector<int> solution(vector<vector<int>> arr) {
    v = arr;

    recursive(0, 0, arr.size());

    return answer;
}