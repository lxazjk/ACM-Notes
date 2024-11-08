#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 7;
int n, t;
struct Node {
	int l, r;
	bool operator < (const Node &rhs) const {
		if(l == rhs.l) return r > rhs.r;
		else return l < rhs.l;
	}
} a[N];
int main() {
	scanf("%d%d", &n, &t);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].l, &a[i].r);
	}
	sort(a, a + n);
	int pos = 0, ans = 0;
	for(int i = 0, j; i < n; i = j + 1) {
		j = i;
		int mx = i;
		if(j < n && a[j].l <= pos + 1) {
			while(j < n && a[j].l <= pos + 1) {
				if(a[j].r > a[mx].r) mx = j;
				j ++ ;
			}
			j -- ;
			if(a[mx].l <= pos + 1) {
				pos = a[mx].r;
				ans ++ ;
			}

			if(pos >= t) {
				printf("%d\n", ans);
				return 0;
			}
		} else {
			printf("-1");
			return 0;
		}
		j = i;
	}
	if(pos >= t) printf("%d\n", ans);
	else printf("%d\n", -1);
	return 0;
}
/*
3 7
1 7
1 3
2 8


4 6
2 4
3 5
1 2
5 6

3 7
1 2
2 4
5 7

3 8
2 6
1 4
3 8


4 7
1 2
2 4
2 5
3 7

5 10
1 2
3 4
2 4
3 7
6 10

5 100
2 10
3 10
2 7
3 10
1 10
*/