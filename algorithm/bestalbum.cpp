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
    } //����� �Է� ��

    i = 0;
    for (string s : genres) {
        for (pair<string, int> p : genCom) {
            if (s == p.first)
                playCom[i] = plays[i];
        }
        i++;


    }
    for (pair<int, int> p : playCom) {
        printf("������ȣ: %d , Ƚ�� : %d \n", p.first, p.second);
    } //������ȣ �� ���� ��~


    return answer;
}