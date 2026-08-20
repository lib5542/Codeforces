#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<vector<char>> A(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) A[i].emplace_back(s[j]);
    }

    char A00 = A[0][0];
    for (int i = 1; i < N; i++) A[i-1][0] = A[i][0];
    for (int i = 1; i < N; i++) A[N-1][i-1] = A[N-1][i];
    for (int i = N-1; i > 0; i--) A[i][N-1] = A[i-1][N-1];
    for (int i = N-1; i > 0; i--) A[0][i] = A[0][i-1];
    A[0][1] = A00;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}