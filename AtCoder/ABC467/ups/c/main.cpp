#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> B(N-1);
    for (int i = 0; i < N-1; i++) cin >> B[i];

    int cost1 = 0;
    int cost2 = 0;
    
    vector<int> A_copy = A;
    for (int i = 0; i < N-1; i++) {
        if ((A_copy[i] + A_copy[i+1]) % M != B[i]) {
            A_copy[i+1] += 1;
            cost1 += 1;
        }
    }
    vector<int> A_copy2 = A;
    cost2 += 1;
    A_copy2[0] += 1;
    for (int i = 0; i < N-1; i++) {
        if ((A_copy2[i] + A_copy2[i+1]) % M != B[i]) {
            A_copy2[i+1] += 1;
            cost2 += 1;
        }
    }

    cout << min(cost1, cost2) << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}