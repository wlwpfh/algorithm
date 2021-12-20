#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Info {
	string name;
	int kor;
	int eng;
	int math;
};

bool comp(Info a, Info b) {
	if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name; //이름 오름차순
	if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
	if (a.kor == b.kor) return  a.eng < b.eng;
	return a.kor > b.kor;


}

int main() {

	int i, n;

	scanf("%d", &n);
	vector <Info> info(n);
	for (i = 0; i < n; i++) {
		cin >> info[i].name >> info[i].kor >> info[i].eng >> info[i].math;

	}

	sort(info.begin(), info.end(), comp);

	for (i = 0; i < n; i++) {
		printf("%s \n", info[i].name.c_str());
	}

	return 0;
}