#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true; int j = 0, k = 0;
    string tmp;
    unordered_map<string, int> dup;
    for (string num : phone_book) {
        dup[num.substr(0, 3)]++;
    }
    printf("\n");

    for (pair <string, int> i : dup) {

        if (i.second > 1) {
            answer = false;
            break;
        }
        else {
            //그래도 더 작은 수가 있을 수 있음
            // for(k=0;k<phone_book.size();k++){
            //     auto a=find(phone_book.begin(), phone_book.end(),i.first);
            //         //자기 자신인 경우는 빼야 함
            //     //printf("%d \n",find(phone_book.begin(), phone_book.end(),i.first));
            //     i.second++;

            //     if(find(phone_book.begin(), phone_book.end(), i.second) && j!=k){
            //     answer=false;
            //     break;
            // }
        //}
       // j++;
            for (string num : phone_book) {
                tmp = num.substr(0, 3);
                printf("tmp는 %s \n", tmp.c_str());

                if (tmp)
            }
            //i.first 
        }
    }

    //     for(pair <string ,int > i : dup){
    //         for(string num : phone_book){
    //         j=0;
    //        if(i.first==num)
    //        {answer=false;
    //         cout << i.first +"는" << num +"을 갖고 있음"  <<endl;
    //        // break;
    //        }else
    //             answer=true;



    //           // printf("j:%d , k:%d \n",j,k);



    //             j++;


    //           // printf("j:%d , k:%d \n",j,k);

    //             j++;
    //         }
    //       k++;
    //     }
    return answer;
}