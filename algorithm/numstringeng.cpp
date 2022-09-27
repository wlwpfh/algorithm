#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int i, j, cur = 0, count = 0;
    int answer = 0;
    string tmp = "";
    vector<string> word{ "zero","one","two","three","four","five","six","seven","eight","nine" };

    vector <int> collect;

    for (i = 0; i < s.size(); i++) {
        if (s[i] >= 48 && s[i] <= 57)
            collect.push_back(s[i] - 48);
        else {
            tmp += s[i];
            for (j = 0; j < word.size(); j++) {
                if (tmp == word[j]) {
                    tmp = "";
                    collect.push_back(j);
                    break;
                }
            }
        }
    }

    for (i = 0; i < collect.size(); i++)
        answer += pow(10, collect.size() - i - 1) * collect[i];

    return answer;
}