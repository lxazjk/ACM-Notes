#include <iostream>
using namespace std;

const int N = 17;
const int S = (1 << 16) + 1;

int n, c[N][N];
char ch[N][N];

namespace subtask {
int count(int s) {
	int cnt = 0;
	for(int i = 0; i < n * n; i++) {
		if(s & (1 << i)) cnt ++ ;
	}
	return cnt;
}

void flip(int i) {
	int x = i / n, y = i % n;
	if(x - 1 >= 0) c[x - 1][y] ^= 1;
	if(x + 1 <= 3) c[x + 1][y] ^= 1;
	if(y - 1 >= 0) c[x][y - 1] ^= 1;
	if(y + 1 <= 3) c[x][y + 1] ^= 1;
	c[x][y] ^= 1; 
}

bool check(int s) {
	for(int i = 0; i < n * n; i++) {
		if(s & (1 << i)) flip(i);
	}
	int w = 0, b = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(c[i][j] == 1) w ++ ;
			else b ++ ;
		}
	}
	for(int i = 0; i < n * n; i++) {
		if(s & (1 << i)) flip(i);
	}
	return w == n * n | b == n * n;
}
void main() {
	int ans = 1e9;
	for(int s = 0; s < (1 << (n * n)); s++) if(check(s))	ans = min(ans, count(s));
	printf("%d\n", ans);
	exit(0);
}
}

namespace STD {

int cnt[S], b[S];

int calc(int s) {
	int final = 0;
	for(int i = 0; i < n; i++) {
		if(s & (1 << i))  {
			final ^= 1 << i;
			if(i + 1 < n) final ^= 1 << (i + 1);
			// cout << i << " " << final << endl;
			if(i - 1 >= 0) final ^= 1 << (i - 1);
			// cout << i << " " << final << endl;
		}
	}
	return final;
}

int calc_white(int s) {
	int ans = cnt[s], pre0 = 0, pre1 = s;
	// cout << s << endl;
	for(int i = 1; i < n; i++) {
		int tmp = b[i - 1] ^ pre0 ^ calc(pre1);
		// cout << tmp << endl;
		pre0 = pre1;
		pre1 = tmp;
		ans += cnt[tmp];
	}
	if((b[n - 1] ^ pre0 ^ calc(pre1)) == 0) return ans;
	else return 1e9;
} 

int calc_black(int s) {
	int ans = cnt[s], pre0 = 0, pre1 = s;
	for(int i = 1; i < n; i++) {
		int tmp = b[i - 1] ^ pre0 ^ calc(pre1) ^ ((1 << n) - 1);
		pre0 = pre1;
		pre1 = tmp;
		ans += cnt[tmp];
	}
	if((b[n - 1] ^ pre0 ^ calc(pre1)) == ((1 << n) - 1)) return ans;
	else return 1e9;
} 

void main() {
	int ans = 1e9;
	// cout << calc(12) << endl;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) b[i] = b[i] << 1 | c[i][j];
	for(int s = 0; s < (1 << n); s++) cnt[s] = cnt[s >> 1] + (s & 1);
	// 	cout << calc_white(12) << endl;
	for(int s = 0; s < (1 << n); s++) {
		ans = min(ans, calc_white(s)), ans = min(ans, calc_black(s));
	}
	if(ans == 1e9) printf("Impossible");
	else printf("%d\n", ans);
}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%s", ch[i]);
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) c[i][j] = (ch[i][j] == 'w');
	if(n <= 4) subtask::main();
	else STD::main();
	return 0;
}