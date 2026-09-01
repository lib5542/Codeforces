#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];

    vector<int> A(P.begin(), P.end());
    next_permutation(A.begin(), A.end());

    int counter = 0;
    while (A < Q) {
        next_permutation(A.begin(), A.end());
        counter++;
    }
    cout << counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}