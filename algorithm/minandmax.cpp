#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string answer;
vector<int> a;
string cur;
string solution(string s) {
    for (int i = 0; i < s.length(); i++) {
        cur += s[i];
        if (s[i] == ' ') {
            a.push_back(stoi(cur));
            cur = "";
        }
    }
    a.push_back(stoi(cur));

    sort(a.begin(), a.end());

    answer = to_string(a[0]) + " " + to_string(a[a.size() - 1]);

    return answer;
}