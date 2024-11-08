#include <iostream>
#include <set>
using namespace std;
const int N = 35 + 7;
int n, m, a[N];	
set < int > s;
set<int>::iterator iter;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), a[i] %= m;
	int pre = n / 2, mx = 0;
	for(int S = 0; S < (1 << pre); S++) {
		int cnt = 0;
		for(int i = 0; i < pre; i++) {
			if(S & (1 << i)) cnt += a[i], cnt %= m;
		}
		mx = max(mx, cnt);
		s.insert(cnt);
	}
	iter = s.end();
	for(int S = 0; S < (1 << (n - pre)); S++) {
		int cnt = 0;
		for(int i = pre; i < n; i++) {
			if(S & (1 << (i - pre))) cnt += a[i], cnt %= m;
		}
		iter = s.upper_bound(m - 1 - cnt);
		iter -- ;
		mx = max(mx, *iter + cnt);
		mx = max(mx, cnt);
	}
	printf("%d\n", mx);
	return 0;
}