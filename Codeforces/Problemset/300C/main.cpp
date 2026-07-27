#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll divider = 1000000007;

bool checkAB(int num, int a, int b) {
    while (num != 0) {
        if (num % 10 != a && num % 10 != b) {
            return false;
        }
        num /= 10;
    }
    return true;
}

ll mpow(ll base, ll exp, ll m) {
    base = base % m;
    ll res = 1;
    while(exp > 0) {
        if (exp & 1) res = res*base % m;
        base = base*base % m;
        exp >>= 1;
    }
    return res;
}

void solve() {
    ll a, b, n;
    cin >> a >> b >> n;

    ll counter = 0;

    vector<ll> fac(n+1);
    fac[0] = 1;
    fac[1] = 1;

    for (ll i = 2; i <= n; i++) {
        fac[i] = fac[i-1]*i % divider;
    }


    for (ll i = 0; i <= n; i++) {
        ll a_count = i;
        ll b_count = n-i;
        ll sumAB = a*a_count + b*b_count;

        if (checkAB(sumAB, a, b)) {
            ll B = fac[a_count]*fac[b_count];
            ll B2 = mpow(B, divider-2, divider);
            counter = (counter + (fac[n] * B2) % divider) % divider;
        }
    }

    cout << counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}