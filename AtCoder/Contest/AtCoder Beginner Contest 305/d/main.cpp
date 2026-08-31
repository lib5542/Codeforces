#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int Q;
    cin >> Q;

    vector<ll> dp(N+1, 0);
    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            dp[i] = dp[i-1] + A[i]-A[i-1];
        } else {
            dp[i] = dp[i-1];
        }
    }

    while (Q--) {
        ll l, r;
        cin >> l >> r;

        int left = lower_bound(A.begin(), A.end(), l) - A.begin();
        int right = upper_bound(A.begin(), A.end(), r) - A.begin() -1;

        ll ans = 0;
        int start, end;
        if (left % 2 == 0) start = left-1;
        else start = left;
        if (start < 0) start = 0;

        if (right % 2 == 0) end = right;
        else end = right+1;

        if (start == 0) start = 1;

        ans += dp[end]-dp[start];

        if (left % 2 == 0 && left != 0) {
            ans -= (l-A[left-1]);
        }
        if (right % 2 == 1) {
            ans -= (A[right+1]-r);
        }
        cout << ans << "\n";
    }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}