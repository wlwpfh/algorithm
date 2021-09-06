#include <string>
#include <iostream>

using namespace std;

string solution(string new_id) {
    int i, end_count = 0;
    string answer = "";
    for (i = 0; i < new_id.length(); i++) {
        if (new_id[i] >= 65 && new_id[i] <= 90) //1
            new_id[i] += 32;
    }
    cout << new_id << endl;
    for (i = 0; i < new_id.length(); i++) {
        if ((new_id[i] >= 65 && new_id[i] <= 90) || (new_id[i] >= 0 && new_id[i] <= 9)
            || new_id[i] == 45 || new_id[i] == 95 || new_id[i] == 44) {
            //answer[i].append(new_id[i]);
        }
        else {
            new_id.erase(remove(new_id.begin(), new_id.end(), new_id[i]),
                new_id.end());
            //answer[i].append(new_id[i]);
        }
    }
    cout << new_id << endl;



    for (i = 1; i < new_id.length(); i++) { //3
        if (new_id[i] == 44 && new_id[i - 1] == 44) {
            new_id.erase(i);
        }
    }

    if (new_id[0] == 44) { //4
        new_id.erase(0);
    }
    else if (new_id[new_id.length() - 1] == 44) {
        new_id.erase(new_id.length() - 1);
    }

    cout << new_id << endl;






    return answer;
}

template <class ForwardIt, class UnaryPredicate>
ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p) {
    first = std::find_if(first, last, p);
    if (first != last)
        for (ForwardIt i = first; ++i != last;)
            if (!p(*i)) *first++ = std::move(*i);
    return first;
}