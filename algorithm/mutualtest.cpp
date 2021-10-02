#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int i, j, min = 0, max = 0, sum = 0;

    vector<double>avg(scores.size());
    for (i = 0; i < scores.size(); i++) {
        min = scores[i][i];
        max = min;
        for (j = 0; j < scores[i].size(); j++) {

            if (min > scores[j][i])
                min = scores[j][i];
            if (max < scores[j][i])
                max = scores[j][i];
            sum += scores[j][i];
            printf("%d��° �л��� ������ %d�� ���� �� %d���̴�. \n", i, scores[j][i], sum);


        }
        if (min == scores[i][i] || max == scores[i][i]) {
            avg[i] = (double)(sum - scores[i][i]) / (scores.size() - 1);
            printf("%d° �л��� �ּڰ�, �ִ��� ���� ����� %f \n", i, avg[i]);
        }
        else {
            avg[i] = (double)sum / (scores.size());
            printf("%d° �л��� ����� %f \n", i, avg[i]);
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