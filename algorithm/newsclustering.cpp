#include <string>
#include <map>
#include <algorithm>

using namespace std;
map<string, int> m;
map<string, int> s1;
map<string, int> s2;
void jacquard(string s, int k) {
    for (int i = 0; i < s.length() - 1; i++) {
        string tmp = "";
        if (s[i] < 65 || s[i]>122 || s[i + 1] < 65 || s[i + 1]>122)
            continue;
        if ((s[i] >= 91 && s[i] <= 96) || (s[i + 1] >= 91 && s[i + 1] <= 96))
            continue;
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
        if (s[i + 1] >= 65 && s[i + 1] <= 90)
            s[i + 1] += 32;
        tmp = s.substr(i, 2);
        if (k == 1)
            s1[tmp]++;
        else
            s2[tmp]++;
        m[tmp]++;
    }
}

int solution(string str1, string str2) {
    int answer = 0;

    jacquard(str1, 1);
    jacquard(str2, 2);
    int a = 0, b = 0;

    for (auto s : m) {
        printf("s= %s \n", s.first.c_str());
        a += min(s1[s.first], s2[s.first]);
        b += max(s1[s.first], s2[s.first]);
    }
    if (a == 0 && b == 0)
        answer = 65536;
    else
        answer = (65536 * a) / b;
    return answer;
}