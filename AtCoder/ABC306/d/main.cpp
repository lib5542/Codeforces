#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAX = 1e16;

void solve() {
    int N;
    cin >> N;

    vector<vector<ll>> dp(N+1, vector<ll>(2, -MAX));
    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i = 1; i <= N; i++) {
        ll x, y;
        cin >> x >> y;

        if (x == 0) {
            dp[i][0] = max(dp[i][0], dp[i-1][0]+y);
            dp[i][0] = max(dp[i][0], dp[i-1][1]+y);
            dp[i][0] = max(dp[i][0], dp[i-1][0]);
            dp[i][1] = dp[i-1][1];
        } else {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i][1], dp[i-1][0]+y);
            dp[i][1] = max(dp[i][1], dp[i-1][1]);
        }
    }

    ll res = max(dp[N][0], dp[N][1]);
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}