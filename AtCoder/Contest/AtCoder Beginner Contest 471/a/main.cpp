#include <bits/stdc++.h>

using namespace std;

void solve() {
    double a, b;
    cin >> a >> b;

    if (a+b == 9 || a-b==9 || a*b==9 || (double) a/b == (double) 9) {
        cout << "Nine";
    } else {
        cout << "Nein";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}