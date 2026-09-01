#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int Q;
    cin >> Q;

    multiset<ll> m;

    while (Q--) {
        int option;
        ll h;
        cin >> option >> h;

        if (option == 1) m.emplace(h);
        else {
            m.erase(m.begin(), m.upper_bound(h));
        }
        cout << m.size() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}