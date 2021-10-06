#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int i, min = arr[0];
    for (i = 1; i < arr.size(); i++) {
        if (min > arr[i])
            min = arr[i];

    }
    if (arr.size() == 1) {
        answer.push_back(-1);
    }
    else {
        for (i = 0; i < arr.size(); i++) {
            if (arr[i] == min) {
                ;
            }
            else {
                answer.push_back(arr[i]);
            }
        }
    }
    return answer;
}