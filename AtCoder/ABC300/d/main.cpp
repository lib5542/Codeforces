#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;

    ll INF = sqrt(N) + 1;

    vector<bool> primes(INF+1, true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 0; i*i < INF; i++) {
        if (primes[i] == true) {
            for (int j = i*i; j <= INF; j += i) {
                primes[j] = false;
            }
        }
    }

    vector<ll> primes_num;
    for (int i = 0; i < INF+1; i++) {
        if (primes[i] == true) primes_num.emplace_back(i);
    }

    int it = primes_num.size();
    ll counter = 0;
    for (int a = 0; a < it; a++) {
        ll aa = primes_num[a];
        if (aa*aa*aa*aa*aa > N) break;
        for (int b = a+1; b < it; b++) {
            ll bb = primes_num[b];
            if (aa*aa*bb*bb*bb > N) break;
            for (int c = b+1; c < it; c++) {
                ll cc = primes_num[c];
                if (aa*aa*bb*cc*cc > N) break;
                counter++;
            }
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