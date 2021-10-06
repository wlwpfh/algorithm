#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> tmp(201);
    int i, j, a, sum = 0;
    bool exit = false;
    for (i = 0; i < numbers.size() - 1; i++) {
        for (j = i + 1; j < numbers.size(); j++) {
            tmp[numbers[i] + numbers[j]]++;
        }

    }
    for (i = 0; i < tmp.size(); i++) {
        if (tmp[i] != 0)
            answer.push_back(i);
    }
    return answer;
}