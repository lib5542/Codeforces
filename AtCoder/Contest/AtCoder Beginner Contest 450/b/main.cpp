#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<vector<int>> C(N+1, vector<int>(N+1, -1));

    for (int i = 1; i <= N-1; i++) {
        for (int j = i+1; j <= N; j++) {
            int c;
            cin >> c;
            C[i][j] = c;
        }
    }

    for (int i = 1; i <= N-1; i++) {
        for (int j = i+1; j <= N; j++) {
            
            for (int k = i; k <= j; k++) {
                if (i < k && k < j) {
                    if (C[i][k] + C[k][j] < C[i][j]) {
                        cout << "Yes";
                        return;
                    }
                }
            }
        }
    }
    cout << "No";



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}