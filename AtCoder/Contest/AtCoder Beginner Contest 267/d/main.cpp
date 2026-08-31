#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<ll> A(N+1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    vector<vector<ll>> dp(N+1, vector<ll>(M+1, -INF));
    for (int i = 0; i <= N; i++) dp[i][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= min(i, M); j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + j*A[i]);
        }
    }
    cout << dp[N][M];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}