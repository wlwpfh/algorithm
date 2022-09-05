#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Hand {
    int x, y;
    Hand(int a, int b) {
        x = a, y = b;
    }
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    Hand left = Hand(3, 0);
    Hand right = Hand(3, 2);

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 3 == 1) { //왼쪽 
            answer += "L";
            left = Hand(numbers[i] / 3, 0);
        }
        else if (numbers[i] % 3 == 0 && numbers[i] != 0) {
            answer += "R";
            right = Hand(numbers[i] / 3 - 1, 2);
        }
        else if (numbers[i] == 0) {
            //가운데 네개의 숫자인 경우
            //거리 비교
            int left_dis = abs(left.x - 3) + abs(left.y - 1);
            int right_dis = abs(right.x - 3) + abs(right.y - 1);
            if (left_dis == right_dis) {
                if (hand == "right") {
                    answer += "R";
                    right = Hand(3, 1);
                }
                else {
                    answer += "L";
                    left = Hand(3, 1);
                }
            }
            else if (left_dis > right_dis) {
                answer += "R";
                right = Hand(3, 1);
            }
            else {
                answer += "L";
                left = Hand(3, 1);
            }
        }
        else {
            int left_dis = abs(left.x - numbers[i] / 3) + abs(left.y - 1);
            int right_dis = abs(right.x - numbers[i] / 3) + abs(right.y - 1);
            if (left_dis == right_dis) {
                if (hand == "right") {
                    answer += "R";
                    right = Hand(numbers[i] / 3, 1);
                }
                else {
                    answer += "L";
                    left = Hand(numbers[i] / 3, 1);
                }
            }
            else if (left_dis > right_dis) {
                answer += "R";
                right = Hand(numbers[i] / 3, 1);
            }
            else {
                answer += "L";
                left = Hand(numbers[i] / 3, 1);
            }
        }
        //  printf("현재 왼손 위치: (%d, %d), 오른손 위치:(%d, %d) \n",
             //   left.x, left.y, right.x, right.y);
    }

    return answer;
}