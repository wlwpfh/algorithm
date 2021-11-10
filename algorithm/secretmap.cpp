#include <string>
#include <vector>

using namespace std;

string to_binary(int m) {
    string s = "";
    if (m == 0)
        return "0";
    else {
        while (m > 0) {
            if (m % 2 == 1) s = "1" + s;
            else s = "0" + s;
            m >>= 1;
        }
        return s;
    }
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

    string a, b, c;
    int i, j;
    long long tmp_a = 0, tmp_b = 0, tmp = 0;
    vector<string> answer(n);

    for (i = 0; i < n; i++) {
        a = to_binary(arr1[i]);
        b = to_binary(arr2[i]); //2진법으로 만들어서
        printf("%s %s \n", a.c_str(), b.c_str());
        tmp_a = stoll(a);
        tmp_b = stoll(b);
        tmp = tmp_a + tmp_b;

        c = to_string(tmp); //string으로 만들었음

        if (c.length() == n)
            ;
        else {
            int t = n - c.length();
            for (j = 0; j < t; j++) {
                c.insert(0, "0");
            }
        }
        for (j = 0; j < n; j++) {
            if (c[j] != '0') {
                answer[i].push_back('#');
            }
            else {
                answer[i].push_back(' ');
            }
        }
    }
    return answer;
}