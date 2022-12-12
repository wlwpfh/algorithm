#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> sorted;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string tmp, answer = "";

    for (auto a : numbers) {
        string tmp = to_string(a);
        sorted.push_back(tmp);
    }
    sort(sorted.begin(), sorted.end(), compare);

    for (auto a : sorted) {

        answer += a;

        if (answer[0] == '0')
            break;
    }

    return answer;
}