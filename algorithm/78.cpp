#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int friends[10001];

struct City {
	int c1;
	int c2;
	int value;
	City(int a, int b, int c) {
		c1 = a;
		c2 = b;
		value = c;
	}
	bool operator<(const City& b)const {
		return value < b.value;
	}
};

int Find(int v) {
	if (v == friends[v])
		return v;
	else {
		return friends[v] = Find(friends[v]);
	}
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a != b) friends[a] = b;
}

int main() {

	vector<City> city;
	int i, n, m, a, b, c, sum = 0;
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		friends[i] = i;
	}

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		city.push_back(City(a, b, c));
	}

	sort(city.begin(), city.end());
	//가중치 값에 의해 오름차순 정렬 

	for (i = 1; i <= n; i++) {
		printf("%d - %d : %d \n", city[i].c1, city[i].c2, city[i].value);
	}

	for (i = 0; i < m; i++) {
		int c1 = Find(city[i].c1);
		int c2 = Find(city[i].c2);
		//서로의 루트찾기  

		if (c1 != c2) { // 서로 다른 집합인 경우  
			sum += city[i].value;
			Union(city[i].c1, city[i].c2);
		}
	}

	printf("%d", sum);

	return 0;
}