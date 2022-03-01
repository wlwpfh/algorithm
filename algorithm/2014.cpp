#include<stdio.h>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

priority_queue <long long, vector<long long>, greater<long long> > pq;
vector<long long> v;
long long max_value;
map<long long, bool> checked; //중복으로 들어가는 것을 방지하기 위해서  
int main() {
	int i, K, N;
	long long tmp;

	scanf("%d %d", &K, &N);

	for (i = 0; i < K; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	pq.push(1);
	checked[1] = true;

	while (N--) {
		long long mul = pq.top();
		pq.pop();

		for (i = 0; i < K; i++) {
			long long output = mul * v[i];

			if (pq.size() > N && output > max_value)
				continue;

			if (checked[output] == true)
				continue;
			else {
				checked[output] = true;
				pq.push(output);
				max_value = max(max_value, output);
			}
		}


	}

	printf("%lld", pq.top());


	return 0;
}