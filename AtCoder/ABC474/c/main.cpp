#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<int> res(N);
    for (int i = 0; i < N; i++) {
        cin >> res[i];
    }

    set<int> tailset;
    vector<int> tail;
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        tail.emplace_back(x);
    }
    reverse(tail.begin(), tail.end());

    vector<int> tailres;
    for (int i = 0; i < Q; i++) {
        if (tailset.find(tail[i]) == tailset.end()) {
            tailres.emplace_back(tail[i]);
            tailset.emplace(tail[i]);
        }
    }
    reverse(tailres.begin(), tailres.end());

    for (int i = 0; i < N; i++) {
        if (tailset.find(res[i]) == tailset.end()) {
            cout << res[i] << " ";
        }
    }

    for (const auto& x : tailres) cout << x << " ";


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}