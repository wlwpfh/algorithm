#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    if (a[0] > b[0])
        return a[0] > b[0];
    if (a[0] == b[0]) {
        return a > b;
    }
    return a[0] > b[0];
}

string solution(vector<int> numbers) {
    string tmp, answer = "";

    int max, i;
    vector<string> sorted;
    for (auto a : numbers) {
        sorted.push_back(to_string(a));
    }
    sort(sorted.begin(), sorted.end(), compare);

    //제일 앞에 오는 숫자가 큰게 오도록
    //만약 숫자가 같은게 있다면 그 다음 글자숫자가 없는 애로.. 
    //그것도 있다면 큰게 오도록
    for (auto a : sorted) {
        printf("%s \n", a.c_str());
        answer += a;
    }

    return answer;
}