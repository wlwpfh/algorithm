#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int i, answer = 0;
    for (i = 0; i < absolutes.size(); i++) {
        if (signs[i] == false) {
            answer -= absolutes[i];
        }
        else {
            answer += absolutes[i];
        }
    }
    return answer;
}