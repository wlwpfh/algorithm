#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int i, checked = 1, a = 1, b = 1, c = 3, onlytwo = 0;
    int correct1 = 0, correct2 = 0, correct3 = 0;

    for (i = 0; i < answers.size(); i++) { //수포자 1
        if (a > 5) {
            a = a % 5;
        }
        if (answers[i] == a) {
            correct1++;
        }
        //  printf("%d ", a);
        a++;

    }
    printf("\n");

    for (i = 0; i < answers.size(); i++) { //수포자 2
        if (i % 2 == 0) {
            onlytwo = 2;
        }

        else if (b > 5) {
            b = b % 5;
        }

        else if (b == 2) {
            b++;
        }

        if (i % 2 == 0) {
            // printf("%d ", onlytwo);
        }
        else {
            //  printf("%d ", b);
        }

        if ((answers[i] == onlytwo && i % 2 == 0) || (answers[i] == b && i % 2 != 0)) {
            correct2++;
            printf("맞춘 아이는 %d ", answers[i]);
        }
        if (onlytwo != 2) {
            b++;
        }
        onlytwo = 0;

    }

    printf("\n");

    for (i = 0; i < answers.size(); i++) { //수포자 3
        if (i % 10 == 0 || i % 10 == 1) {
            c = 3;
        }
        else if (c == 3) {
            c++;
        }
        else if (i % 10 == 2) {
            c = 1;
        }
        // printf("%d ", c);
        if (answers[i] == c) {
            correct3++;
        }

        if (checked % 2 == 0) {
            c++;
        }
        checked++;

    }
    printf("\n");

    if (correct1 == correct2 && correct2 == correct3) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    else if (correct1 == correct2 && correct2 != 0) {
        answer.push_back(1);
        answer.push_back(2);
    }
    else if (correct2 == correct3 && correct2 != 0) {
        answer.push_back(2);
        answer.push_back(3);
    }
    else if (correct1 == correct3 && correct3 != 0) {
        answer.push_back(1);
        answer.push_back(3);
    }
    else if (correct1 > correct2 && correct1 > correct3) {
        answer.push_back(1);
    }
    else if (correct3 > correct2 && correct3 > correct2) {
        answer.push_back(3);
    }
    else if (correct2 > correct1 && correct2 > correct3) {
        answer.push_back(2);
    }



    return answer;
}