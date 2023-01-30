#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes) {
    int position = 0, camera = 1;

    sort(routes.begin(), routes.end());

    position = routes[0][1];

    for (int i = 0; i < routes.size(); i++) {
        if (routes[i][0] <= position) {
            position = min(position, routes[i][1]);
        }
        else {
            camera++;
            position = routes[i][1];
        }
    }
    return camera;
}