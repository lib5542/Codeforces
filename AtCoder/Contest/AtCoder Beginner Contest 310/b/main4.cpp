#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> P(N);
    vector<int> C(N);
    vector<vector<int>> F(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> C[i];
        for (int j = 0; j < C[i]; j++) {
            int f;
            cin >> f;
            F[i].emplace_back(f);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (i == j) continue;
            if (P[i] < P[j]) continue;

            




        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}