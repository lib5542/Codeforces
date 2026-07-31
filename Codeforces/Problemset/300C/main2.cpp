#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll divider = 1000000007;

ll mpow(ll a, ll e) {
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = (res * a) % divider;
        a = (a * a) % divider;
        e >>= 1;
    }
    return res;
}

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    vector<ll> fac(n+1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i-1] * i) % divider;
    }

    ll res = 0;

    for (int i = 0; i <= n; i++) {
        int c_a = i;
        int c_b = n-c_a;

        int s = c_a * a + c_b * b;
        bool ex_num = true;
        while (s > 0) {
            if (s % 10 != a && s % 10 != b) {
                ex_num = false;
                break;
            }
            s = s / 10;
        }
        if (ex_num) {
            ll temp = (fac[c_a] * fac[n-c_a]) % divider;
            res = (res + (fac[n] * mpow(temp, divider-2))) % divider;
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}