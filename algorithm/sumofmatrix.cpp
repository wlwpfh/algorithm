#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> tmp;
    int i, j;
    for (i = 0; i < arr1.size(); i++) {

        for (j = 0; j < arr1[i].size(); j++) {
            tmp.push_back(arr1[i][j] + arr2[i][j]);

        }
        answer.push_back(tmp);
        tmp.clear();
    }
    return answer;
}