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

    //���� �տ� ���� ���ڰ� ū�� ������
    //���� ���ڰ� ������ �ִٸ� �� ���� ���ڼ��ڰ� ���� �ַ�.. 
    //�װ͵� �ִٸ� ū�� ������
    for (auto a : sorted) {
        printf("%s \n", a.c_str());
        answer += a;
    }

    return answer;
}