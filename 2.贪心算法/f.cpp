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

const int N = 1000 + 5;

int n, a[N], b[N];

void clear() {

}

void read() {
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
}

void solve() {
	sort(a, a + n);
	sort(b, b + n);
	int la = 0, lb = 0, ra = n - 1, rb = n - 1, ans = 0;
	for(int i = 0; i < n; i++) {	
		if(a[ra] < b[rb]) la ++ , rb -- , ans -= 200;
		else if(a[ra] > b[rb]) ra -- , rb -- , ans += 200;
		// else if(a[la] < b[la]) la ++ , rb -- , ans -= 200;
		else if(a[la] > b[lb]) la ++ , lb ++ , ans += 200;
		else if(a[la] < b[rb]) la ++ , rb --, ans -= 200;
	}
	printf("%d\n", ans);
}

int main() {
	while(scanf("%d", &n) != EOF) {
		if(!n) return 0;
		clear();
		read();
		solve();
	}
	return 0;
}
/*
7
11 9 8 8 4 3 2
11 9 8 8 4 3 2
*/