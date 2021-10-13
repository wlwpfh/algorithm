#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    //vector<int> same(scores.size());
    int i, j, min = 100, max = 0, same_min, same_max, sum = 0;

    vector<double>avg(scores.size());
    for (i = 0; i < scores.size(); i++) {
        same_min = 0, same_max = 0;
        min = 1000;
        max = 0;
        for (j = 0; j < scores[i].size(); j++) {
            if (min == scores[j][i])
                same_min++;
            if (max == scores[j][i])
                same_max++;

            if (min > scores[j][i])
                min = scores[j][i];
            if (max < scores[j][i])
                max = scores[j][i];
            sum += scores[j][i];

        }
        if ((min == scores[i][i] && same_min == 0) || (max == scores[i][i] && same_max == 0)) {
            avg[i] = (double)(sum - scores[i][i]) / (scores.size() - 1);

        }
        else {
            avg[i] = (double)sum / (scores.size());

        }
        sum = 0;
    }
    for (i = 0; i < avg.size(); i++) {
        if (avg[i] >= 90) {
            answer += 'A';
        }
        else if (80 <= avg[i]) {
            answer += 'B';
        }
        else if (70 <= avg[i]) {
            answer += 'C';
        }
        else if (50 <= avg[i]) {
            answer += 'D';
        }
        else {
            answer += 'F';
        }
    }
    return answer;
}