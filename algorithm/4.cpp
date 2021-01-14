#include<iostream>
using namespace std;

int main04() {

	int n=0;

	int a=0;

	int max = -200;
	int min = 200;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		
		cin >> a;

		if (max < a) {
			max = a;
		}
		if (min > a) {
			min = a;
		}
		
	}
	cout << max - min << endl;

	return 0;
}