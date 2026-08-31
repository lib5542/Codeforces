#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> P(N);
    vector<int> Q(N);

    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];

    vector<int> A(N);
    iota(A.begin(), A.end(), 1);

    int count = 0;

    do {
        if (P < A && A < Q) {
            count++;
        }
    } while (next_permutation(A.begin(), A.end()));

    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}