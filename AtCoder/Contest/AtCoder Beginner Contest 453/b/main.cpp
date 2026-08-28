#include <bits/stdc++.h>

using namespace std;

void solve() {
    int T, X;
    cin >> T >> X;


    int sav;

    for (int i = 0; i <= T; i++) {
        int a;
        cin >> a;

        if (i == 0) {
            sav = a;
            cout << 0 << " " << a << "\n";
        } else {

            if (abs(sav-a) >= X) {
                cout << i << " " << a << "\n";
                sav = a;
            }

        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}