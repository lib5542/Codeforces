#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int counter = 0;
    for (int i = 0; i < N-2; i++) {
        if (A[i] < A[i+1] && A[i+1] > A[i+2]) {
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