#include <vector>

using namespace std;

int solution(int N, vector<int> stations, int W)
{
    int answer = 0;

    int index = 0, position = 1;

    while (position <= N) {
        if (index < stations.size() && stations[index] - W <= position) {
            //있는 경우
            position = stations[index++] + W + 1;
        }
        else {
            answer++;
            position += 2 * W + 1;
        }
    }

    return answer;
}