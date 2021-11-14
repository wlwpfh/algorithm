#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int i, j, count = 1;
    unordered_map< string, int> checked;
    unordered_map< string, int> forPrint;

    for (i = 0; i < participant.size(); i++) {
        //if(checked.find(participant[i]))
        {checked.insert(make_pair(participant[i], 0));
        printf("bool: %d particpant: %s \n", checked.find(participant[i]), participant[i].c_str()); }
    }

    for (i = 0; i < completion.size(); i++) {
        if (checked.count(completion[i]))
            checked[completion[i]] = 1;
    }
    for (pair<string, int> k : checked)
    {

        if (k.second != 1)
            answer = k.first;
    }
    if (answer == "") {
        // for(pair<string, int> k : checked){
        //     pair<string, int> count=find(participant.begin(), participant.end(), k.first);
        //     printf("%s %d",count.first, count.second);

        //}
        printf("%d", equal(participant.begin(), participant.end(), completion.begin()));
        answer = participant[equal(participant.begin(), participant.end(), completion.begin())];
    }


    return answer;
}