#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    map<int, int> A_index;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_index[A[i]] = i;
    }
    for (int i = 0; i < N; i++) cin >> B[i];

    if (N == 1) {
        cout << 0;
        return;
    }

    int counter = 0;
    int current = A_index[B[N-1]];
    for (int i = N-2; i >= 0; i--) {
        if (A_index[B[i]] < current) {
            current = A_index[B[i]];
        } else {
            counter++;
        }
    }
    cout << counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}