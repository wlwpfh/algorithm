#include<string>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    int i, j = 1, answer = 0;
    cin >> T;
    string word = "";
    string forComp = "";

    char tmp[30];
    //printf("%s ",first.c_str());
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%s", tmp);

        forComp = tmp;
        //printf("forComp: %s \n", forComp.c_str());
        j = 1;
        for (i = 0; i < j; i++) {
            for (j = i + 1; j < 30; j++) {
                if (forComp.substr(i, j) == forComp.substr(j, j))
                {
                    answer = j - i;
                    break;
                }

            }
        }


        printf("#%d %d \n", test_case, answer);

    }
    return 0;
}