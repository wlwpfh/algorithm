#include<stdio.h>
#include<string>
using namespace std;

int main() {
	int n, k;
	scanf_s("%d %d", &n, &k);
	int a, b, c;

	int answer = 0;
	string tmp = to_string(k);
	//	string s;
	//string test = to_string(01) + to_string(22) + to_string(45);
	//printf("%s \n", test.c_str());
	for (a = 0; a <= n; a++) {
		for (b = 0; b <= 59; b++) {
			for (c = 0; c <= 59; c++) {
				//0인 경우를 다 넣어주기

				string s = to_string(a) + to_string(b) + to_string(c);
				if (a < 10)
					s.insert(0, "0");
				if (b < 10)
					s.insert(2, "0");
				if (c < 10)
					s.insert(4, "0");
				if (s.find(tmp) != string::npos)
				{
					answer++;
					//printf("시간 :%s , answer: %d \n", s.c_str(), answer);
				}
			}
		}
	}


	printf("%d", answer);

	return 0;
}