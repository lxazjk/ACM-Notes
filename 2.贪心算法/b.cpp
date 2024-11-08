#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int N = 100 + 5;
int n;
multiset < int > s;
struct Node {
	int l, r;
	bool operator < (const Node &rhs) const {
		return l < rhs.l;
	}
} a[N];

int main() {
	while(scanf("%d", &n)) {
		if(!n) {
			return 0;
		}
		s.clear();
		for(int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].l, &a[i].r);
			s.insert(a[i].r);
		}
		sort(a, a + n);
		int ans = 0, pos = 0;
		for(int i = 0, j; i < n; i=j) {
			j = i;
			while(j < n && a[j].l < pos) {
				s.erase(a[j].r);
				j ++ ;
			} 
			if(!s.empty()) {
				pos = *s.begin();
				ans ++ ;
			} else {
				break;
			}
		}
		printf("%d\n", ans);		
	}
	return 0;
}