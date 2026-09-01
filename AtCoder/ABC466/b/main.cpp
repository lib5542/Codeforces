#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> C(N);
    vector<int> S(N);

    for (int i = 0; i < N; i++) {
        cin >> C[i] >> S[i];
    }

    vector<int> maxSize(M, -1);
    for (int i = 0; i < N; i++) {
        if (S[i] > maxSize[C[i]-1]) {
            maxSize[C[i]-1] = S[i];
        }
    }

    for (int i = 0; i < M; i++) {
        cout << maxSize[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}