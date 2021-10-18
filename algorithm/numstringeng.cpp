#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
string erase_char(string str, int index) {
    string buff;
    buff = str.substr(0, index);
    buff += str.substr(index + 1, str.size() - (index + 1));
    return buff;
}
int solution(string s) {
    int i, j, cur = 0, count = 0;
    int answer = 0;
    vector<string> word{ "zero","one","two","three","four","five","six","seven","eight","nine" };

    vector <int> collect;

    for (i = 0; i < s.size(); i++) {
        if (s[i] >= 48 && s[i] <= 57) {
            printf("%c는 숫자이다. \n", s[i]);
            collect.push_back(s[i] - 48);
            printf("숫자는 %d \n", collect[i]);
            //s.erase(i,1);
            erase_char(s, i);
            printf("현재 남은 s는 %s \n", s.c_str());
        }
        else {
            printf("%c는 숫자가 아니다. \n", s[i]);
            for (j = 0; j < word.size(); j++) {
                if (s.find(word[j]) != -1) { //찾았다면 없애고 탈출하기
                    printf("문자인 %d %d %d \n", j, s.find(word[j]), word[j].length());
                    collect.push_back(j);
                    s.erase(s.find(word[j]), word[j].length());
                    printf("현재 남은 s는 %s \n", s.c_str());
                    break;


                }
            }
        }

    }

    for (i = 0; i < collect.size(); i++) {
        printf("%d ", collect[i]);
    }

    return answer;
}