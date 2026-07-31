#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    set<int> moved;

    int A_index = 0;
    for (int B_index = 0; B_index < N; B_index++) {

        while (moved.find(A[A_index]) != moved.end()) A_index++;

        if (A[A_index] != B[B_index] && moved.find(A[A_index]) == moved.end()) {
            moved.emplace(B[B_index]);
        } else {
            A_index++;
        }
    }
    cout << moved.size();

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}