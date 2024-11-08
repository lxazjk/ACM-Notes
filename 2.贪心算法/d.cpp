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
const int base = 29;
const int mod = 1e9 + 7;

int n;
ll hash_1[N], hash_2[N];
char s[N];

int qpow(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) ret = 1ll * ret * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return ret;
}

bool check(int x, int l, int r) {
	return (hash_1[x + l - 1] - 1ll * hash_1[l - 1] * qpow(base, x) % mod + mod) % mod == (hash_2[r - x + 1] - 1ll * hash_2[r + 1] * qpow(base, x) % mod + mod) % mod;
}

pair < int, int > half(int len, int L, int R) {
	int l = 0, r = len, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid, L, R)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	return make_pair(L + ans, R - ans);
}

bool get(int l, int r) {
	// use 二分 to solve
	pair < int, int > pii = half(r - l + 1, l, r);
	l = pii.first, r = pii.second;
	if(s[l] < s[r]) return 0;
	else return 1;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 0; i < n; i++) hash_1[i] = 1ll * hash_1[i - 1] * base % mod + s[i] - 'A';
	for(int i = n - 1; i > 0; i--) hash_2[i] = 1ll * hash_2[i + 1] * base % mod + s[i] - 'A';
	int l = 0, r = n - 1;
	int cnt = 0;
	while(l <= r) {
		if(s[l] < s[r]) {
			printf("%c", s[l++]);
			cnt ++ ;
		} else if(s[l] > s[r]) {
			printf("%c", s[r--]);
			cnt ++ ;
		} else if(s[l] == s[r]) {
			if(get(l, r) == 0) {
				printf("%c", s[l]);
				cnt ++ ;
				l ++ ;
			} else {
				printf("%c", s[r]);
				cnt ++ ;
				r -- ;
			}
		}
		if(cnt % 80 == 0) puts("");
	}
	return 0;
}