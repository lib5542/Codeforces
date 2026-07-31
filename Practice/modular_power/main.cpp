#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll divider = 1000000007;

ll mpow(ll base, ll exp) {
    ll res = 1;
    base = base % divider;

    while (exp > 0) {
        if (exp & 1) res = res * base % divider;
        base = base * base % divider;
        exp >>= 1;
    }

    return res;
}

int main() {
    ll res = mpow(2, 10);
    cout << res;
    return 0;
}