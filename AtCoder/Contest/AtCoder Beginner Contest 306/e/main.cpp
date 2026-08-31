#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<ll> A(N+1, 0);
    set<pair<ll, ll>> k_set;
    set<pair<ll, ll>> n_k_set;

    for (int i = 1; i <= K; i++) {
        k_set.insert({0, i});
    }

    for (int i = K+1; i <= N; i++) {
        n_k_set.insert({0, i});
    }

    ll res = 0;

    for (int i = 0; i < Q; i++) {
        ll x, y;
        cin >> x >> y;

        if (k_set.find(pair(A[x], x)) != k_set.end()) {
            k_set.erase(pair(A[x], x));
            res -= A[x];
        }
        if (n_k_set.find(pair(A[x], x)) != n_k_set.end()) n_k_set.erase(pair(A[x], x));

        A[x] = y;

        n_k_set.emplace(A[x], x);
        while (k_set.size() < K && !n_k_set.empty()) {
            auto nk_top = *n_k_set.rbegin();
            n_k_set.erase(nk_top);
            k_set.insert(nk_top);
            res += nk_top.first;
        }

        if (!n_k_set.empty() && !k_set.empty()) {
            auto k_bot = *k_set.begin();
            auto nk_top = *n_k_set.rbegin();
            
            while (!k_set.empty() && !n_k_set.empty() && (k_bot < nk_top)) {
                k_set.insert(nk_top);
                n_k_set.insert(k_bot);
                res += nk_top.first;

                k_set.erase(k_bot);
                n_k_set.erase(nk_top);
                res -= k_bot.first;

                k_bot = *k_set.begin();
                nk_top = *n_k_set.rbegin();
            }
        }

        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}