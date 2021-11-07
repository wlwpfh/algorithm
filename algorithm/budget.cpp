#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int i, sum = 0, curr = 0, max = 0, answer = 0;
    for (i = 0; i < d.size(); i++) {
        sum += d[i];
    }
    if (sum >= budget)
        return d.size();
    else {
        for (i = 0; i < d.size(); i++) {
            if (curr + d[i] > budget)
                break;
            else if (curr + d[i] == budget) {
                max++;
                break;
            }
            else {
                max++;
                curr += d[i];
            }
        }
        return max;
    }
}