#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    vector<int> S(K+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[A[i]]++;
    }

    int maxSt = *max_element(S.begin(), S.end());
    int res = 0;

    for (int i = 1; i <= K; i++) {
        if (S[i] >= maxSt-1) res++;
    }

    cout << res;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}