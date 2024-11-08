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
const int M = 100 + 5;

#define int ll

struct Node {
	int x, y;
	ll v;
	bool operator < (const Node &rhs) const {
		if(x == rhs.x) return y > rhs.y;
		return x > rhs.x;
	}
} a[N], b[N];

int n, m, c[M];

// 结论1:相同数量 x越高 肯定越高

signed main() {
	while(scanf("%lld%lld", &n, &m) != EOF) {
		for(int i = 0; i < n; i++) { // 机器
			scanf("%lld%lld", &a[i].x, &a[i].y);
		}
		for(int i = 0; i < m; i++) { // 物品
			scanf("%lld%lld", &b[i].x, &b[i].y);
			b[i].v = b[i].x * 500 + 2 * b[i].y;
		}
		sort(a, a + n);
		sort(b, b + m);
		int j = 0, cnt = 0;
		ll ans = 0;
		memset(c, 0, sizeof(c));
		for(int i = 0; i < m; i++) {
			while(j < n && a[j].x >= b[i].x) {
				c[a[j].y] ++ ;
				j ++ ;
			}
			for(int k = b[i].y; k <= 100; k++) {
				if(c[k]) {
					cnt ++ ;
					c[k] -- ;
					ans += b[i].v;
					break;
				}
			}
		}
		printf("%lld %lld\n", cnt, ans);
	}
	return 0;
}