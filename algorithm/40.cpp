#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main40_() {
	int n, m, i;
	scanf("%d", &n);

	vector <int> arr1(n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
	}
	sort(arr1.begin(), arr1.end()); //시작점과 끝을 넣으면 오름차순으로 정렬된다. 
	scanf("%d", &m);

	vector <int> arr2(m);
	vector <int> common(m);
	for (i = 0; i < m; i++) {
		scanf("%d", &arr2[i]);
	}
	sort(arr2.begin(), arr2.end());
	int p1 = 0, p2 = 0, p_c = 0;

	while (p1 < n && p2 < m) {
		if (arr1[p1] == arr2[p2]) {
			common[p_c++] = arr1[p1++]; 
			p2++;
		}
		else if (arr1[p1] > arr2[p2]) {
			p2++;
		}
		else {
			p1++;
		}
	}

	for (i = 0; i < p_c; i++) {
		printf("%d ", common[i]);
	}

	return 0;
}