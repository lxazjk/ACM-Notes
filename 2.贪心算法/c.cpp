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

inline ll read() {
    ll f = 1, x = 0;char ch;
    do {ch = getchar();if (ch == '-')f = -1;} while (ch > '9' || ch < '0');
    do {x = x * 10 + ch - '0';ch = getchar();} while (ch >= '0' && ch <= '9');
    return f * x;
}

const int N = 1e3 + 5;

int n, d;

struct Node {
	double l, r;
	bool operator < (const Node & rhs) const {
		return r < rhs.r;
	}
} a[N];

int main() {
	int tim = 1;
	while (scanf ("%d %d", &n, &d) && n && d) {
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			int x = read(), y = read();
			if(abs(y) > d) flag = 1;
			a[i].l = x - 1.0 * sqrt(1.0 * d * d - 1.0 * y * y);
			a[i].r = x + 1.0 * sqrt(1.0 * d * d - 1.0 * y * y);
		}
		if(flag) {
			printf("Case %d: -1\n", tim ++ );
			continue;
		}
		sort(a, a + n);
		int cnt = 1;
		double right = a[0].r;
		for(int i = 1; i < n; i++) {
			if (a[i].l > right) {
				cnt ++;
				right = a[i].r;
			} 
			else if(a[i].r < right) {
				right = a[i].r;
			} 
		}
		printf("Case %d: %d\n", tim ++, cnt);
	}
	return 0;
}
