#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int i;
    for (i = 0; i < s.length(); i++) {
        if ((s[i] >= 65 && s[i] <= 90) && s[i] + n > 90) {
            answer += s[i] - 26 + n;
        }
        else if ((s[i] >= 97 && s[i] <= 122) && s[i] + n > 122) {
            answer += s[i] - 26 + n;
        }
        else if (s[i] == ' ') {
            answer += ' ';
        }
        else {
            answer += s[i] + n;
        }
    }
    return answer;
}