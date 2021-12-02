#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer(genres.size());
    unordered_map<string, int> genCom;
    unordered_map<int, int> playCom;
    int i = 0;
    for (string s : genres) {

        genCom[s] += plays[i];
        i++;
    }
    for (pair<string, int> p : genCom) {
        printf("gen: %s , plays: %d \n", p.first.c_str(), p.second);
    } //제대로 입력 완

    i = 0;
    for (string s : genres) {
        for (pair<string, int> p : genCom) {
            if (s == p.first)
                playCom[i] = plays[i];
        }
        i++;


    }
    for (pair<int, int> p : playCom) {
        printf("고유번호: %d , 횟수 : %d \n", p.first, p.second);
    } //고유번호 잘 들어가기 완~


    return answer;
}