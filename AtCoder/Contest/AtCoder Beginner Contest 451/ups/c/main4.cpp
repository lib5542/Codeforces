#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int Q;
    cin >> Q;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    while (Q--) {
        int option;
        ll h;
        cin >> option >> h;

        if (option == 1) pq.emplace(h);
        else {
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