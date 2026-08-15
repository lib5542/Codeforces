#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll Q, V;
    cin >> Q >> V;

    vector<pair<ll, ll>> v;

    while (Q--) {
        int q;
        cin >> q;

        if (q == 1) {
            ll t, w;
            cin >> t >> w;
            v.emplace_back(t, w);
        } else if (!v.empty()) {
            ll t;
            cin >> t;

            ll maxi = -1;
            ll idx = -1;
            for (int i = 0; i < v.size(); i++) {
                v[i].second += (t - v[i].first);
                v[i].first = t;

                if (v[i].second > maxi) {
                    maxi = v[i].second;
                    idx = i;
                }
            }
            cout << min(maxi, V) << "\n";
            v.erase(v.begin() + idx);

        } else {
            cout << -1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}