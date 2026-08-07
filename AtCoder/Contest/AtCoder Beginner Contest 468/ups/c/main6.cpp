#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> P(N), Q(N);
    for (int& p : P) cin >> p;
    for (int& q : Q) cin >> q;

    vector<bool> visited(N, false);
    vector<int> temp;
    int res = 0;

    auto backT = [&](auto& self, int counter) -> void {

        if (counter == N) {
            if (P < temp && temp < Q) {
                res++;
            } else {
                return;
            }
        }

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.emplace_back(i+1);

                self(self, counter+1);

                temp.pop_back();
                visited[i] = false;
            }
        }
    };

    backT(backT, 0);

    cout << res;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}