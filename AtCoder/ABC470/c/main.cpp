#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;

    // 1 base index
    vector<int> A(N+1, 0);
    set<int> over_one;
    int res = 0;

    while (Q--) {
        int oper;
        cin >> oper;

        if (oper == 1) {
            int x;
            cin >> x;
            res = res^A[x];
            A[x]++;
            res = res^A[x];
            over_one.emplace(x);
        } else {
            vector<int> over_one_v(over_one.begin(), over_one.end());
            for (int& t : over_one_v) {
                res = res^A[t];
                A[t]--;
                res = res^A[t];
                if (A[t] == 0) over_one.erase(t);
            }
        }
        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}