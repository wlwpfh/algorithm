#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> score;
    for (int i = 0; i < survey.size(); i++) {
        auto a = survey[i];
        if (choices[i] == 4)
            continue;
        score[choices[i] < 4 ? a.at(0) : a.at(1)] += abs(choices[i] - 4);
    }

    if (score['R'] >= score['T'])
        answer += "R";
    else
        answer += "T";

    if (score['C'] >= score['F'])
        answer += "C";
    else
        answer += "F";

    if (score['J'] >= score['M'])
        answer += "J";
    else
        answer += "M";
    if (score['A'] >= score['N'])
        answer += "A";
    else
        answer += "N";
    return answer;
}