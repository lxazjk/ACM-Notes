#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

const int INF = 2139062143;

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

const int N = 1e5 + 7;

#define int ll

struct Node {
	int t, v;
	bool operator < (const Node &rhs) const {
		if(t == rhs.t) return v < rhs.v;
		return t < rhs.t; 
	}
} a[N];

int T, n;

priority_queue < int , vector <int> , greater<int> > q;

void clear() {
	while(!q.empty()) q.pop();
}

void read() {
	scanf("%lld", &n);
	for(int i = 0; i < n; i++) scanf("%lld%lld", &a[i].t, &a[i].v);
}

void solve() {
	int ans = 0;
	sort(a, a + n);
	// cout << a[0].t << " " << a[0].v << endl;
	for(int i = 0; i < n; i++) {
		if(q.size() < a[i].t) {
			ans += a[i].v;
			q.push(a[i].v);
		} else {
			int t = q.top();
			if(t < a[i].v) {
				ans += a[i].v - t;
				q.pop();
				q.push(a[i].v);
			}
		}
	}
	printf("%lld\n", ans);
}

signed main() {
	T = 1;
	while(T--) {
		clear();
		read();
		solve();
	}
	return 0;
}