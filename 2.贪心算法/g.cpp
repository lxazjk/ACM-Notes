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

const int N = 5e5 + 7;

#define int ll

int T, n, a[N];

struct Node {
	int x;
	bool f;
	bool operator < (const Node &rhs) const {
		if(x == rhs.x) return f < rhs.f;
		return x > rhs.x;
	}
};

priority_queue < Node > q;

void clear() {
	while(!q.empty()) q.pop();
}

void read() {
	scanf("%lld", &n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
}

void solve() {
	int ans = 0, cnt = 0;
	for(int i = 0; i < n; i++) {
		// 三种情况 
		// 第一种 什么事情都不做 ans = ans
		// 第二种 卖掉 那么这种情况 要么是反悔 要么是直接卖掉 直接小顶堆里面的最小值 区别是cnt += 2 / 0
		// 第三种 买进来 放进小顶堆
		// if(i == 3) cout << t.x << endl;
		if(!q.empty() && q.top().x < a[i]) {
			Node t = q.top();
			ans += a[i] - t.x;
			q.pop();
			cnt += t.f ? 0 : 2;
			Node xx; xx.x = a[i], xx.f = 1;
			q.push(xx);
			if(t.f) {
				t.f = 0;
				q.push(t);
			}
		} else {
			q.push((Node){a[i], 0});
		}
		// printf("iteration : %d ans = %d cnt = %d\n", i, ans, cnt);
	}
	printf("%lld %lld\n", ans, cnt);
}

signed main() {
	scanf("%lld", &T);
	while(T--) {
		clear();
		read();
		solve();
	}
	return 0;
}