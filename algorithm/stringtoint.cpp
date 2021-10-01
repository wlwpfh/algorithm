#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string tmp = s;
    int answer = 0;
    if (s[0] == '+' || s[0] == '-') {
        tmp.substr(1);
        answer = stoi(tmp);
    }
    else {
        answer = stoi(s);
    }
    return answer;
}