#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    int i, end_count = 0;
    string answer = new_id;

    for (i = 0; i < answer.length(); i++) {
        if (answer[i] >= 65 && answer[i] <= 90) //1
            answer[i] += 32;
    }
    printf("1. 소문자로 치환 결과: %s \n", answer.c_str());

    for (i = 0; i < answer.length(); i++) { //2
        if ((answer[i] >= 'a' && answer[i] <= 'z') || (answer[i] >= '0' && answer[i] <= '9')
            || answer[i] == '-' || answer[i] == '_' || answer[i] == '.') {
            continue;
        }
        else {
            answer.erase(i, 1);
            i--;
        }
    }
    printf("2. 다른 문자 제거 결과: %s \n", answer.c_str());



    for (i = 1; i < answer.length(); i++) { //3
        if (answer[i] == '.' && answer[i - 1] == '.') {
            answer.erase(i, 1);
            i--;
        }
    }
    printf("3. 다른 문자 제거 결과: %s \n", answer.c_str());

    if (answer[0] == '.') { //4
        answer.erase(0, 1);
    }
    else if (answer[answer.length() - 1] == 44) {
        answer.erase(answer.length() - 1);
    }


    printf("4. 다른 문자 제거 결과: %s \n", answer.c_str());


    if (answer.length() == 0)
        answer += "a";

    printf("5. 다른 문자 제거 결과: %s \n", answer.c_str());

    if (answer.length() >= 16) {
        answer.erase(15, answer.length());
    }
    printf("6-1. 다른 문자 제거 결과: %s \n", answer.c_str());

    if (answer[answer.length() - 1] == '.')
        answer.erase(answer.length() - 1, 1);

    printf("6-2. 다른 문자 제거 결과: %s \n", answer.c_str());

    if (answer.length() <= 2) {
        while (answer.length() != 3) {
            answer += answer[answer.length() - 1];
        }
    }

    return answer;
}