#include <map>
#include <vector>

using namespace std;

map<int, int> m;

int solution(vector<int> elements) {

    int sum = 0;
    for (int i = 0; i < elements.size(); i++) {
        m[elements[i]]++;
        sum = elements[i];
        for (int j = i + 1; j < elements.size() + i; j++) {
            if (j >= elements.size())
                sum += elements[j - elements.size()];
            else
                sum += elements[j];
            m[sum]++;
        }
    }
    return m.size();
}