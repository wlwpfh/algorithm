#include <string>
#include <vector>
#include<iostream>
#include<sstream>


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
    vector<pair <string, string>> in_out; //나오고 들어온 uid를 넣기
    vector<pair <string, string>> info{};
    pair<string, string> tmp;
    int i, j; istringstream ss; string a, b;
    for (i = 0; i < record.size(); i++) {
        tmp = split(record[i]);
        if (record[i].find("Enter") != -1) {
            info.push_back(pair<string, string>(tmp.first, tmp.second));
            in_out.push_back(pair<string, string>("in", tmp.first));
        }
        else if (record[i].find("Change") != -1) {
            for (j = 0; j < info.size(); j++) {
                if (info[j].first == tmp.first) {
                    info[j].second = tmp.second;
                }
            }
        }
        else { // leave
            in_out.push_back(pair<string, string>("out", tmp.first));
        }
    }
    for (i = 0; i < in_out.size(); i++) {
        if (in_out[i].first == "in") {
            for (j = 0; j < info.size(); i++) {
                if (in_out[i].second == info[j].first) {
                    a = info[j].second;
                    break;
                }
            }
            printf("%s님이 들어왔습니다. \n", a.c_str());
        }
        else { //"out"
           //answer.push_back(+)
        }
    }

    return answer;
}