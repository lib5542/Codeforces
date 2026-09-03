#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    ll left, right;

    cin >> left;
    cin >> right;

    for (int i = 2; i < n; i++) {
        ll w;
        cin >> w;

        if (left <= right) left += w;
        else right += w;
    }

    ll diff = abs(left-right);

    vector<ll> weights = {100, 50, 20, 10, 5, 2, 1};

    ll res = 0;

    for (ll& w : weights) {
        ll a = diff / w;
        res += a;
        diff %= w;
    }

    cout << res;

}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}