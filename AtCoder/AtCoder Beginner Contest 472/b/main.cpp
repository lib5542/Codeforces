#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;


    vector<int> L(N);
    int LS = 0;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        LS += L[i];
    }

    int cur = 0;
    int res = INT_MAX;
    for (int i = 0; i < N; i++) {
        cur += L[i];
        LS -= L[i];
        res = min(res, abs(cur-LS));
    }
    
    cout << res;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}