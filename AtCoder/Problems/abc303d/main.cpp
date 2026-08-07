#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll X, Y, Z;
    cin >> X >> Y >> Z;

    string S;
    cin >> S;

    vector<vector<ll>> dp(S.size()+1, vector<ll>(2, LLONG_MAX));
    dp[0][0] = 0;
    dp[0][1] = Z;

    for (int i = 1; i <= S.size(); i++) {
        if (S[i-1] == 'a') {
            dp[i][0] = min(dp[i][0], dp[i-1][0]+X);
            dp[i][0] = min(dp[i][0], dp[i-1][1]+Z+X);
            dp[i][1] = min(dp[i][1], dp[i-1][1]+Y);
            dp[i][1] = min(dp[i][1], dp[i-1][0]+Z+Y);
        } else {
            dp[i][0] = min(dp[i][0], dp[i-1][0]+Y);
            dp[i][0] = min(dp[i][0], dp[i-1][1]+Z+Y);
            dp[i][1] = min(dp[i][1], dp[i-1][1]+X);
            dp[i][1] = min(dp[i][1], dp[i-1][0]+Z+X);
        }
    }
    cout << min(dp[S.size()][0], dp[S.size()][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}