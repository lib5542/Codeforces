#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll divider = 1000000007;

ll mpow(ll base, ll exp) {
    ll res = 1;
    base %= divider;

    while (exp > 0) {
        if (exp & 1) res = (res * base) % divider;
        base = base * base % divider;
        exp >>= 1;
    }

    return res;
}

// return a/b % divider
ll FlT(ll a, ll b) {
    a %= divider;
    b %= divider;

    ll B = mpow(b, divider-2);
    return (a * B) % divider;
}

int main() {
    ll res = FlT(4, 2);
    cout << res;
    return 0;
}