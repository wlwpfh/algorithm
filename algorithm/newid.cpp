#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    int i, end_count = 0;
    string answer = "";
    for (i = 0; i < new_id.length(); i++) {
        if (new_id[i] >= 65 && new_id[i] <= 90)
            new_id[i] += 32;
    }

    for (i = 0; i < new_id.length(); i++) {
        if ((new_id[i] >= 65 && new_id[i] <= 90) || (new_id[i] > 0 && new_id[i] < 9)
            || new_id[i] == 45 || new_id[i] == 95 || new_id[i] == 44) {
            //answer[i].append(new_id[i]);
        }
        else {
            new_id.erase(i);
//      answer[i].append(new_id[i]);
        }
    }



    for (i = 1; i < new_id.length(); i++) {
        if (new_id[i] == 44 && new_id[i - 1] == 44) {
            new_id[i] = 32;
        }
    }

    if (new_id[0] == 44) {
        new_id[0] = 32;
    }
    // if(new_id[new_id.length()-1]==44){
    //     new_id[new_id.length()-1]=32;
    // }




    return answer;
}