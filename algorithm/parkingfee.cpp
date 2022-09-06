#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

string inout;

pair<string, string> split(string s) {
    istringstream ss(s);
    string stringBuffer;

    pair<string, string> pair_s;
    string a, b;
    int i = 0;
    if (s.length() == 13) {
        while (getline(ss, stringBuffer, ' ')) {

            if (i == 0) a = stringBuffer;
            if (i == 1) b = stringBuffer;
            if (i == 2) inout = stringBuffer;
            i++;
        }
    }
    else {
        while (getline(ss, stringBuffer, ':')) {

            if (i == 0) a = stringBuffer;
            if (i == 1) b = stringBuffer;
            i++;
        }
    }

    // printf("%s %s \n",a.c_str(), b.c_str());
    pair_s = make_pair(a, b);
    return pair_s;
}

int timeCal(string a, string b) {
    printf("length:%d \n", a.length());
    pair<string, string> now = split(a);

    pair<string, string> future = split(b);

    int now_hour = stoi(now.first);
    int now_min = stoi(now.second);
    int future_hour = stoi(future.first);
    int future_min = stoi(future.second);
    printf("%d:%d -> %d:%d \n", now_hour, now_min, future_hour, future_min);
    int min = future_min - now_min;
    int hour = future_hour - now_hour;

    if (min < 0) {
        hour -= 1;
        min = 60 - now_min + future_min;
    }
    return hour * 60 + min;
}

int calFee(int fee) {
    return 2;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> car_time;
    //�� ��ȣ, ���� �ð� 
    map<string, int> charge;
    //������ �� ������Ʈ�ϱ� 
    for (int i = 0; i < records.size(); i++) {
        //printf("length:%d \n",records[i].length());
        pair<string, string> car_info = split(records[i]);
        string car_num = car_info.second;
        string time = car_info.first;
        if (inout == "OUT") {
            //���� ���� ��� 
            string tmp = car_time[car_num];
            //printf("�ð�:%s \n", tmp.c_str());
            car_time[car_num] = "0"; //���� �������ϱ� ������Ʈ 
            int a = timeCal(tmp, time);
            printf("%d ", a);
            charge[car_num] = timeCal(tmp, time);

        }
        else if (inout == "IN") {
            //���� ���� ���
            car_time[car_num] = time;
            //printf("time:%s \n", time.c_str());
        }
    }

    for (auto a : charge) {
        printf("%s -> %d�� \n", a.first.c_str(), a.second);
    }

    return answer;
}