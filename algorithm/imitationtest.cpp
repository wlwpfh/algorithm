#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
    vector<int>answers;
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);

    vector<int> answer;
    int i, checked = 1, a = 1, b = 0, c = 3, onlytwo = 2;
    int correct1 = 0, correct2 = 0, correct3 = 0;

    for (i = 0; i < answers.size(); i++) { //수포자 1
        if (a > 5) {
            a = a % 5;
        }
        if (answers[i] == a) {
            correct1++;
        }
        printf("%d ", a);
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
        if (i % 2 == 1) {
            b++;
        }
        if (i % 2 == 0) {
            printf("%d ", onlytwo);
        }
        else {
            printf("%d ", b);
        }

        if ((answers[i] == onlytwo) || answers[i] == b) {
            correct2++;
        }



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
        printf("%d ", c);
        if (answers[i] == c) {
            correct3++;
        }

        if (checked % 2 == 0) {
            c++;
        }
        checked++;

    }
    printf("\n");
    return 0;
}