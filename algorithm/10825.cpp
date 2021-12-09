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
	if (a.kor > b.kor)
		return true;
	else if (a.kor == b.kor) {
		if (a.eng > b.eng)
			return true;
		else if (a.eng == b.eng)
			if (a.math > b.math)
				return true;
			else if (a.math == b.math)
				if (a.name > b.name)
					return true;
				else
					return false;
			else
				return false;
	}
	else
		return false;
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