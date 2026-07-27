#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    int counter = 0;
    vector<bool> moved(N, false);

    int j = 0;
    for (int i = 0; i < N; i++) {

        while (j < N && moved[A[j]-1]) j++;

        if (A[j] != B[i] && !moved[B[i]-1]) {
            moved[B[i]-1] = true;
            counter++;
        } else {
            j++;
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