#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;

    vector<pair<int, int>> p(N);
    ll s = 0;

    for (int i = 0; i < N; i++) {
        cin >> p[i].first >> p[i].second;
        s += p[i].second;
    }

    sort(p.begin(), p.end());

    ll day = 1;
    for (int i = 0; i < N; i++) {
        if (K >= s) {
            cout << day;
            return;
        }
        day = p[i].first+1;
        s -= p[i].second;
    }
    cout << day;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}