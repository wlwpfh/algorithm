#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;

    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].length(); j++)
            cities[i][j] = tolower(cities[i][j]);
    }

    for (int i = 0; i < cities.size(); i++) {
        //         for(int j=0;j<v.size();j++)
        //                     printf("%s \n",v[j].c_str());

        auto a = find(v.begin(), v.end(), cities[i]);
        if (a == v.end()) { //�ȿ� �ִ� ���� ���� ��� 
            answer += 5;
            if (v.size() < cacheSize) //�� ���� �� �ִ� ��� 
                v.push_back(cities[i]);
            else if (v.size() == cacheSize && cacheSize != 0) { //������ ��� 
                v.erase(v.begin());
                v.push_back(cities[i]);
            }
        }
        else {
            answer += 1;

            v.erase(find(v.begin(), v.end(), cities[i]));
            v.push_back(cities[i]);
        }
    }
    return answer;
}