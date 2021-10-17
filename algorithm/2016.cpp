#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string> answer = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
    string ans;
    vector<int> month = { 0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int i;
    int sum = 0;

    for (i = 1; i < a; i++) {
        sum += month[i];
    }

    ans = answer[(sum + 4 + b) % 7];

    return ans;
}