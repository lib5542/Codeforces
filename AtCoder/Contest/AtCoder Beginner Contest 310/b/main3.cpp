#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> P(N);
    vector<int> C(N);
    vector<vector<int>> F(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> C[i];
        for (int j = 0; j < C[i]; j++) {
            int f;
            cin >> f;
            F[i].emplace_back(f);
        }
    }

    int supIdx = 0;
    while (supIdx < N) {
        for (int i = 0; i < N; i++) {
            if (i == supIdx) continue;
            if (P[i] < P[supIdx]) continue;
            if (P[i] == P[supIdx] && C[i] >= C[supIdx]) continue;
            if (C[i] > C[supIdx]) continue;

            int supFcounter = 0;
            bool tobreak = false;
            if (C[supIdx] > C[i]) {
                for (int j = 0; j < C[i]; j++) {
                    if (F[i][j] != F[supIdx][supFcounter]) {
                        supFcounter++;
                    }
                    supFcounter++;
                    if (supFcounter > C[supIdx]) {
                        tobreak = true;
                        break;
                    }
                }
            } else {
                for (int j = 0; j < C[i]; j++) {
                    if (F[i][j] != F[supIdx][j]) {
                        tobreak = true;
                        break;
                    }
                }
            }
            if (tobreak) continue;

            cout << "Yes";
            return;
        }
        supIdx++;
    }
    cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}