#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

pair<string, string> split(string s) {
    istringstream ss(s);
    string stringBuffer;
    pair<string, string> pair_s;
    string a, b;
    int i = 0;
    while (getline(ss, stringBuffer, ' ')) {

        if (i == 0) a = stringBuffer;
        if (i == 1) b = stringBuffer;
        i++;

    }
    // printf("%s %s \n",a.c_str(), b.c_str());
    pair_s = make_pair(a, b);
    return pair_s;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> count; //�� ������ �Ű���� Ƚ��
    map<string, set<string>> overlap;
    //�Ű��� ���, �Ű� ���� ��� 
    for (int i = 0; i < report.size(); i++) {
        pair<string, string> now = split(report[i]);
        //�Ű��� ���, �Ű���� ���

        if (overlap[now.first].find(now.second) != overlap[now.first].end())
            continue;

        overlap[now.first].insert(now.second);
        count[now.second]++;
    }


    for (auto a = overlap.begin(); a != overlap.end(); a++) {
        for (auto b : overlap[a->first]) {
            printf("%s -> %s�� �Ű��� \n", a->first.c_str(), b.c_str());
        }
    }

    for (string s : id_list) {
        int counts = 0;
        for (string person : overlap[s]) {
            if (count[person] >= k)
                counts++;
        }
        answer.push_back(counts);
    }

    return answer;
}