#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int N, M;
    ll D;
    cin >> N >> M >> D;

    vector<ll> A(N);
    vector<ll> B(M);

    for (ll& a : A) cin >> a;
    for (ll& b : B) cin >> b;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int pA = N-1;
    int pB = M-1;

    ll res = -1;

    while (pA >= 0 && pB >= 0) {
        if (abs(A[pA]-B[pB]) <= D) {
            res = A[pA]+B[pB];
            break;
        } else {
            if (A[pA] > B[pB]) pA--;
            else pB--;
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}