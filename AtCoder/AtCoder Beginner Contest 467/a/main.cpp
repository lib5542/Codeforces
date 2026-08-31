#include <iostream>

using namespace std;

void solve() {
    int H;
    int W;
    cin >> H >> W;

    if (W * 100 * 100 >= 25 * H * H) cout << "Yes";
    else cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}