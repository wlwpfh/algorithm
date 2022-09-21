#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

bool cmp2(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> musicTotal;
    //장르별 두 노래만 
    map<string, int> genresTotal;
    for (int i = 0; i < genres.size(); i++) {
        musicTotal[genres[i]].push_back(make_pair(i, plays[i]));
        genresTotal[genres[i]] += plays[i];
    }
    vector<pair<string, int>> v(genresTotal.begin(), genresTotal.end());
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        printf("%s -  %d \n", v[i].first.c_str(), v[i].second);
    }

    for (auto& a : musicTotal) {
        sort(a.second.begin(), a.second.end(), cmp2);
    }

    for (int i = 0; i < v.size(); i++) {
        int count = 0;

        for (auto i : musicTotal[v[i].first]) {
            if (count == 2)
                break;
            answer.push_back(i.first);
            count++;
        }
    }

    return answer;
}