#include <iostream>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
ll n, a[N], s[N], t[N];
int main() {
	scanf("%lld", &n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]), s[i] = (i ? s[i - 1] : 0) + a[i], t[i] = (i ? t[i - 1] : 0) ^ a[i];
	ll r = 0, ans = 0;
	for(int l = 0; l < n; l++) {
		while(r < n && (t[r] ^ t[l - 1]) == s[r] - s[l - 1]) r ++ ;
		// cout << l << " " << r << endl;
		if((t[r - 1] ^ t[l - 1]) == s[r - 1] - s[l - 1])
		ans += max(0ll, r - l);
	}
	printf("%lld\n", ans);
	return 0;
}