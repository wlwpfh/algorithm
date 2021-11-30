#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true; int j = 0, k = 0;
    string tmp;
    unordered_map<string, int> dup;
    for (string num : phone_book) {
        dup[num.substr(0, 4)]++;
    }
    printf("\n");

    for (pair <string, int> i : dup) {
        k = 0;
        if (i.second > 1) {
            answer = false;
            break;
        }
        else {

            for (string num : phone_book) {
                if (num.substr(0, 2) == i.first && k != j) {
                    answer = false;
                    printf("num는 %s이고 i는 %s이다. \n", num.c_str(), i.first.c_str());
                    break;
                }

                k++;
            }

        }
        j++;
    }
    return answer;
}