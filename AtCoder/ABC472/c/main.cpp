#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    queue<pair<ll, ll>> rec;
    ll total = 0;
    for (int i = 0; i < N; i++) {
        if (total + A[i] <= K) {
            total += A[i];
            rec.emplace(A[i], 1);
            cout << "Yes\n";
        } else {
            rec.emplace(A[i], 0);
            cout << "No\n";
        }
        if (rec.size() >= M) {
            if (rec.front().second == 1) {
                total -= rec.front().first;
            }
            rec.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}