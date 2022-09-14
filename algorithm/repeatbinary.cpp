#include <string>
#include <vector>

using namespace std;

string to_binary(int num) {
    string s = "";
    while (num != 0) {
        s += num % 2 == 0 ? '0' : '1';
        num /= 2;
    }
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    int zero_count = 0, change_count = 0, tmp, tmp_zero = 0;
    //printf("%d \n",stoi(s));
    while (s != "1") {

        tmp = 0, tmp_zero = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0')
                tmp_zero++;
        }
        tmp = s.length() - tmp_zero; //0제거 후 길이 
        s = to_binary(tmp); //이진 변환 결과
        zero_count += tmp_zero;
        change_count++;
    }
    answer.push_back(change_count);
    answer.push_back(zero_count);
    return answer;
}