#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {

    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) {
        A[i] %= K;
    }

    sort(A.begin(), A.end());

    ll minA = A[0];
    ll maxA = A[A.size()-1];

    ll answer = maxA-minA;
    for (int i = 0; i < N-1; i++) {
        A[i] += K;
        maxA = A[i];
        minA = A[i+1];
        answer = min(answer, maxA-minA);
    }
    cout << answer;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}