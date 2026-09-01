#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s.size() % 5 == 0) cout << "Yes";
    else cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    소수 출력 사용 시
    cout << fixed;
    cout.precision(10);
    */

    solve();

    return 0;
}