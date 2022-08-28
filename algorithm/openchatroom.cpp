#include <string>
#include <vector>
#include<iostream>
#include<sstream>
#include<queue>
#include<map>

using namespace std;
pair<string, string> split(string s) {
    istringstream ss(s);
    string stringBuffer;
    pair<string, string> pair_s;
    string a, b;
    int i = 0;
    while (getline(ss, stringBuffer, ' ')) {

        if (i == 1) a = stringBuffer;
        if (i == 2) b = stringBuffer;
        i++;

    }
    //printf("%s %s \n",a.c_str(), b.c_str());
    pair_s = make_pair(a, b);
    return pair_s;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    pair<string, string> tmp;
    map<string, string> info; // uid / 이름

    int i, j;

    for (i = 0; i < record.size(); i++) {
        tmp = split(record[i]);

        if (tmp.second != "")
            info[tmp.first] = tmp.second;

    }

    for (i = 0; i < record.size(); i++) {
        tmp = split(record[i]);
        if (record[i].find("Enter") != -1)
            answer.push_back(info[tmp.first] + "님이 들어왔습니다.");
        else if (record[i].find("Leave") != -1)
            answer.push_back(info[tmp.first] + "님이 나갔습니다.");
    }



    return answer;
}