#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (int i = 0 ; i < N; i++) cin >> A[i] >> B[i];

    int M;
    cin >> M;

    vector<string> S(M);
    for (int i = 0; i < M; i++) cin >> S[i];

    // ups: 척추를 M개 고르고 갈비를 최악의 경우 M개 보아야 하는데 어떻게 O(MlogM)으로 푸는지. 


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}