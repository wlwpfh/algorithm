#include <string>
#include <vector>
#include<string.h>

using namespace std;

string solution(string s) {
    string answer = "";
    int i, count = 0;
    for (i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            count = 0;
            answer += ' ';
            printf("공백 \n");
        }
        else {
            if (count % 2 == 0) {
                printf("%d번째 %c \n", count, s[i]);
                answer += toupper(s[i]);
            }
            else {
                printf("%d번째 %c \n", count, s[i]);
                answer += tolower(s[i]);
            }
            count++;
        }
    }
    printf("%s", answer.c_str());
    return answer;
}