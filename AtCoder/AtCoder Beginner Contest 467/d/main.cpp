#include <bits/stdc++.h>

using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {

        int p1, p2, q1, q2, r1, r2, s1, s2;
        cin >> p1 >> p2 >> q1 >> q2 >> r1 >> r2 >> s1 >> s2;

        if (p1-q1 == 0 && r1-s1 == 0) {
            if ((p2+q2)/2 == (r2+s2)/2) cout << "Yes\n";
            else cout << "No\n";
        } else if (p1-q1 == 0 || r1-s1 == 0) {
            cout << "Yes\n";
        } else {
            if ((p2-q2)/(p1-q1) == (r2-s2)/(r1-s1)) {

                double pq1 = (p1+q1)/2;
                double pq2 = (p2+q2)/2;

                double rs1 = (r1+s1)/2;
                double rs2 = (r2+s2)/2;

                double d = (pq2-rs2)/(pq1-rs1);

                if (d * (p2-q2)/(p1-q1) == -1 && d * (r2-s2)/(r1-s1) == -1) cout << "Yes\n";
                else cout << "No\n";
            } else {
                cout << "Yes\n";
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