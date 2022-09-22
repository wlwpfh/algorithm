#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

bool pass = true;

vector<int> solution(int n, vector<string> words) {
    int i;
    vector<int> answer;
    map<string, int> overlap;
    overlap[words[0]]++;
    for (i = 1; i < words.size(); i++) {
        char prev = words[i - 1][words[i - 1].length() - 1];
        char next = words[i][0];
        overlap[words[i]]++;
        if (prev != next || overlap[words[i]] != 1) {
            pass = false;
            break;
        }

    }

    if (pass) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(i % n + 1);
        answer.push_back(i / n + 1);
    }



    return answer;
}