#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, bool> dup;

    for (string num : phone_book) {
        if (dup[num.substr(0, 3)] == true)
            dup[num.substr(0, 3)] = false;
        else
            dup[num.substr(0, 3)] = true;
        //printf("%s %d \n",num.substr(0,3).c_str(),false);
    }
    printf("\n");
    for (pair <string, bool > i : dup) {
        if (i.second == true)
            answer = true;
        else
            answer = false;

    }
    return answer;
}