#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

void solve() {
    double H, W;
    cin >> H >> W;

    H = H / 100;

    double bmi = W / H / H;
    if (bmi + EPS >= 25) cout << "Yes";
    else cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}