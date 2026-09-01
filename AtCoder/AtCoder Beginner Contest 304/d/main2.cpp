#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll W, H;
    cin >> W >> H;

    int N;
    cin >> N;

    vector<pair<ll, ll>> pos(N);
    for (int i = 0; i < N; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    ll AN;
    cin >> AN;
    vector<int> A(AN);
    for (int i = 0; i < AN; i++) cin >> A[i];

    ll BN;
    cin >> BN;
    vector<int> B(BN);
    for (int i = 0; i < BN; i++) cin >> B[i];


    map<pair<ll, ll>, int> m;

    for (int i = 0; i < N; i++) {
        ll curX = pos[i].first;
        ll curY = pos[i].second;

        ll curX_idx = upper_bound(A.begin(), A.end(), curX) - A.begin();
        ll curY_idx = upper_bound(B.begin(), B.end(), curY) - B.begin();

        m[pair(curX_idx, curY_idx)]++;
    }

    int resMin = 1000000;
    int resMax = -1;

    for (const auto& [piece, count] : m) {
        resMin = min(resMin, count);
        resMax = max(resMax, count);
    }

    if ((AN+1)*(BN+1) > m.size()) resMin = 0;
    cout << resMin << " " << resMax;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}