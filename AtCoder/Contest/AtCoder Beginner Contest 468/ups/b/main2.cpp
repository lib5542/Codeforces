#include <bits/stdc++.h>

using namespace std;
const int INF = 100000;

void solve() {
    int M, D;
    cin >> M >> D;

    string S;
    cin >> S;

    vector<int> dp(M, INF);

    int recent = -INF;
    for (int i = 0; i < M; i++) {
        if (S[i] == 'G') recent = i;
        dp[i] = min(i-recent, dp[i]);
    }
    recent = INF;
    for (int i = M-1; i >= 0; i--) {
        if (S[i] == 'G') recent = i;
        dp[i] = min(recent-i, dp[i]);
    }

    int res = 0;
    for (int i = 0; i < M; i++) {
        if (dp[i] > D) res++;
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}