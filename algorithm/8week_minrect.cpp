#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int i, tmp, answer = 0;

    vector<int> max_size = *max_element(sizes.begin(), sizes.end());
    printf("%d %d \n", max_size[0], max_size[1]);
    for (i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1]) { //세로가 가로보다 더 긴 경우
            swap(sizes[i][0], sizes[i][1]);
        }
        if (sizes[i][0] > max_size[0]) {
            max_size[0] = sizes[i][0];
        }
        if (sizes[i][1] > max_size[1])
            max_size[1] = sizes[i][1];
    }


    return max_size[0] * max_size[1];
}