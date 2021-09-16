#include <string>
#include <vector>

using namespace std;
//주의할 점: 동명이인이 있음!
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<int> end(participant.size());
    int i, j;
    for (i = 0; i < participant.size(); i++) {
        for (j = 0; j < completion.size(); j++) {
            if (participant[i] == completion[j] && completion[j] != "0") {
                end[i] = 1;
                completion[j] = "0";
            }
        }
    }
    for (i = 0; i < end.size(); i++) {
        if (end[i] == 0) {
            answer += participant[i];
            break;
        }
    }
    return answer;
}