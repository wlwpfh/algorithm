#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;

bool check(vector<string> want, vector<int> number) {
    int count = 0; bool flag = true;
    for (auto a : want) {
        if (m[a] != number[count]) {
            flag = false;
            break;
        }
        count++;
    }
    return flag;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    for (int i = 0; i < 10; i++)
        m[discount[i]]++;

    for (int i = 1; i < discount.size(); i++) {
        if (check(want, number))
            answer++;
        if (i + 9 < discount.size())
            m[discount[i + 9]]++;

        m[discount[i - 1]]--;
    }
    return answer;
}