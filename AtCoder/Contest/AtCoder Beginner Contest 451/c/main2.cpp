#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    int Q;
    cin >> Q;
    while (Q--) {
        ll x, h;
        cin >> x >> h;
        if (x == 1) {
            pq.emplace(h);
        } else {
            while (!pq.empty() && pq.top() <= h) pq.pop();
        }
        cout << pq.size() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}