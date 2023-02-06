#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    string a_head = "", b_head = "";
    int a_index = 0, b_index = 0, i;
    for (i = 0; i < a.length(); i++) {
        if (a[i] >= 'A' && a[i] <= 'Z')
            a_head += (a[i] + 32);
        if (a[i] >= 'a' && a[i] <= 'z')
            a_head += a[i];
        if (a[i] == ' ' || a[i] == '.' || a[i] == '-')
            a_head += a[i];
        if (a[i] >= '0' && a[i] <= '9')
            break;
    }
    a_index = i;
    for (i = 0; i < b.length(); i++) {
        if (b[i] >= 'A' && b[i] <= 'Z')
            b_head += (b[i] + 32);
        if (b[i] >= 'a' && b[i] <= 'z')
            b_head += b[i];
        if (b[i] == ' ' || b[i] == '.' || b[i] == '-')
            b_head += b[i];
        if (b[i] >= '0' && b[i] <= '9')
            break;
    }
    b_index = i;

    if (a_head != b_head)
        return a_head < b_head;
    string a_num = "", b_num = "";
    //number
    for (i = a_index; i < a.length(); i++) {
        if (a[i] >= '0' && a[i] <= '9' && a_num.length() <= 5)
            a_num += a[i];
        else
            break;
    }
    for (i = b_index; i < b.length(); i++) {
        if (b[i] >= '0' && b[i] <= '9' && b_num.length() <= 5)
            b_num += b[i];
        else
            break;
    }
    int tmp_a = stoi(a_num);
    int tmp_b = stoi(b_num);
    return tmp_a < tmp_b;
}

vector<string> solution(vector<string> files) {
    vector<string> answer = files;

    stable_sort(answer.begin(), answer.end(), compare);


    return answer;
}