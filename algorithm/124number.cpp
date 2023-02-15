#include <string>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";

    int div = 0, sum = n;

    while (sum > 0) {
        div = sum % 3;
        sum /= 3;

        if (div == 0) {
            answer += "4";
            sum--;
        }
        else if (div == 1) {
            answer += "1";
        }
        else {
            answer += "2";
        }
    }
    reverse(answer.begin(), answer.end());

    return answer;
}