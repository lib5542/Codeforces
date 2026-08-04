#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll divider = 1000000007LL;

ll mpow(ll a, ll e) {
    a %= divider;
    ll ans = 1;

    while (e > 0) {
        if (e & 1) ans = (ans * a) % divider;
        a = (a * a) % divider;
        e >>= 1;
    }

    return ans;
}

// return a/b % divider
ll FlT(ll a, ll b) {
    a %= divider;
    b %= divider;

    ll c = mpow(b, divider-2);
    return (a * c) % divider;
}

int main() {

    ll ans = FlT(10, 6);
    cout << ans;

    return 0;
}