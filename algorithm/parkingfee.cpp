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
    if (s.length() >= 10) {
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
    pair_s = make_pair(a, b);
    return pair_s;
}

int timeCal(string a, string b) {
    pair<string, string> now = split(a);
    pair<string, string> future = split(b);
    int now_hour = stoi(now.first);
    int now_min = stoi(now.second);
    int future_hour = stoi(future.first);
    int future_min = stoi(future.second);
    int min = future_min - now_min;
    int hour = future_hour - now_hour;

    if (min < 0) {
        hour -= 1;
        min = 60 - now_min + future_min;
    }
    return hour * 60 + min;
}

int feeCal(int feeTime, vector<int> moneyInfo) {
    int money = moneyInfo[1];
    if (feeTime <= moneyInfo[0]) //기본시간보다 작다면
        return moneyInfo[1];
    feeTime -= moneyInfo[0];

    return money + ((feeTime - 1) / moneyInfo[2] + 1) * moneyInfo[3];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> car_time; //차번호, 들어온 시간 
    map<string, int> isOut; //차번호, 나갔는지 여부 확인(0,1)
    map<string, int> charge; //차번호, 총 시간 

    for (int i = 0; i < records.size(); i++) {
        pair<string, string> car_info = split(records[i]);
        string car_num = car_info.second;
        string time = car_info.first;
        if (inout == "OUT") {
            string tmp = car_time[car_num];
            car_time[car_num] = "0"; //차가 나갔으니까 업데이트 
            charge[car_num] += timeCal(tmp, time);
            isOut[car_num] = 0;
        }
        else if (inout == "IN") {
            car_time[car_num] = time;
            isOut[car_num] = 1;
        }
    }

    for (auto a : isOut) { //나가지 않은 차들을 23:59분에 요금 
        if (a.second == 1)
            charge[a.first] += timeCal(car_time[a.first], "23:59");
    }
    for (auto a : charge) {
        int fee = feeCal(a.second, fees);
        answer.push_back(fee);
    }

    return answer;
}