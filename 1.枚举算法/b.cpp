#include <iostream>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int n, m, a[N], s[N];
signed main() {
	while(scanf("%lld%lld", &n, &m) != EOF) {
		// memset(s, 0, sizeof(s));
		for(int i = 0; i < n; i++) scanf("%lld", &a[i]), s[i] = (i ? s[i - 1] : 0) + a[i];
		int r = 0, ans = n + 1;
		for(int l = 0; l < n; l++) {
			while(r < n && s[r] - s[l - 1] < m) r ++ ;
			if(r < n && s[r] - s[l - 1] >= m) ans = min(ans, r - l + 1);
		}
		if(ans == n + 1) printf("0\n");
		else printf("%lld\n", ans);
	}
	return 0;
}