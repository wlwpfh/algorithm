#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string a, answer = "";
    int i, loc;
    for (i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            loc = i;
        }
    }
    a = to_string(loc);
    answer = "김서방은 " + a + "에 있다";
    return answer;
}