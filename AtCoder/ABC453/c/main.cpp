#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
vector<ll> L;

ll res;

void mov(double pos, ll idx, ll counter) {
    res = max(res, counter);
    if (idx == N) return;

    double moved = pos - L[idx];
    if (pos * moved < 0) mov(moved, idx+1, counter+1);
    else mov(moved, idx+1, counter);

    moved = pos + L[idx];
    if (pos * moved < 0) mov(moved, idx+1, counter+1);
    else mov(moved, idx+1, counter);

}

void solve() {
    cin >> N;

    L.resize(N);
    for (ll i = 0; i < N; i++) cin >> L[i];

    mov(0.5, 0, 0);
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}