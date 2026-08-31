#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    int M;
    cin >> M;

    vector<string> S(M);
    set<tuple<int, int, char>> cont;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;

        S[i] = s;

        for (int j = 0; j < s.size(); j++) {
            cont.emplace((int) s.size(), j+1, s[j]);
        }
    }

    for (int i = 0; i < M; i++) {
        string selected = S[i];
        bool found = true;

        if (selected.size() != N) {
            cout << "No" << "\n";
            continue;
        }

        for (int j = 0; j < N; j++) {
            tuple<int, int, char> k = {A[j], B[j], selected[j]};
            if (cont.find(k) == cont.end()) {
                found = false;
                break;
            }
        }
        if (found) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}