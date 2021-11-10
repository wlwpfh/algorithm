#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int i, j;
    unordered_map< string, int> checked;
    for (i = 0; i < participant.size(); i++) {
        checked.insert(make_pair(participant[i], 0));
    }

    for (i = 0; i < completion.size(); i++) {
        if (checked.count(completion[i]))
            checked[completion[i]] = 1;
    }
    for (auto& x : checked)
        if (x.second == 0)
            answer = x.first;
    return answer;
}