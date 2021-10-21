#include <string>
#include <vector>

using namespace std;
string to_binary(int n) {
    string s = "";
    while (n > 0) {
        if (n % 2 == 1) s = "1" + s;
        else s = "0" + s;
        n >>= 1;
    }
    //printf("%s ",s.c_str());
    return s;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    string a, b, c;
    int i, j;
    long long tmp_a, tmp_b, tmp;

    for (i = 0; i < n; i++) {
        a = to_binary(arr1[i]);
        b = to_binary(arr2[i]); //2진법으로 만들어서
        //printf("%s %s \n",a.c_str(), b.c_str());
        tmp_a = stoll(a);
        tmp_b = stoll(b);
        tmp = tmp_a + tmp_b;

        //printf("%d+ %d= %d \n",tmp_a,tmp_b,tmp);
        c = to_string(tmp); //string으로 만들었음

        //printf("%s ",c.c_str());
        if (c.length() == n)
            ;
        else {
            tmp = n - c.length();
            for (j = 0; j < tmp; j++) {
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
        //printf("%s %s \n",c.c_str(),answer[i].c_str());
    } //2진법으로 만듦. 
    return answer;
}