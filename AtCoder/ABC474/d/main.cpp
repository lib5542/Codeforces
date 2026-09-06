#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MAX = 1e18;

void solve() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<ll> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int idx = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] > B[i]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) cout << "No";
    else {
        cout << "Yes\n";
        for (int i = 0; i < N; i++) {
            if (i != idx) {
                cout << 1 << " ";
            } else {
                cout << MAX << " ";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}