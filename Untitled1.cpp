#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        map<int,int> cnt;
        cnt[0] = 1;
        long long ans = 0;
        for (int a, s = 0, i = 0; i < n; ++i) {
            scanf("%d", &a);
            a = (a % k + k) % k;
            s = (s + a) % k;
            ans += cnt[s]++;
        }
        printf("%lld\n", ans);
    }
}
