#include <string>
#include <vector>

using namespace std;

vector<vector<int>> d;
bool visited[9];
int answer = 0;
void track(int count, int sleepy, int index) {
    if (sleepy < 0)
        return;
    for (int i = 0; i < d.size(); i++) {
        if (!visited[i] && sleepy >= d[i][0]) {
            visited[i] = true;
            track(count + 1, sleepy - d[i][1], index + 1);
            visited[i] = false;
        }
    }
    answer = max(answer, count);
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    d = dungeons;
    track(0, k, 0);
    return answer;
}