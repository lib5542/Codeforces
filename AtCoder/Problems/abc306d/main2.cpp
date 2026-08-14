#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAX = 1e16;

void solve() {
    int N;
    cin >> N;

    ll antid = 0;
    ll poison = -MAX;

    for (int i = 1; i <= N; i++) {
        ll x, y;
        cin >> x >> y;

        if (x == 0) {
            antid = max({antid, antid+y, poison+y});
        } else {
            poison = max(poison, antid+y);
        }
    }

    ll res = max(antid, poison);
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}