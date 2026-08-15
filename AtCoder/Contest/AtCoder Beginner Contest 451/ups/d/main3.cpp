#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MAX = 1e9;

vector<ll> power_of_2;
set<ll> goods;

void dfs(ll x1) {
    for (ll& x2 : power_of_2) {
        ll temp = x2;
        int counter = 0;
        while (temp > 0) {
            temp = temp / 10;
            counter++;
        }
        ll con = x1*(pow(10, counter)) + x2;
        if (con <= MAX) {
            goods.emplace(con);
            dfs(con);
        } else return;
    }
}

void solve() {
    ll mul = 1;
    for (int i = 0; i < 31; i++) {
        power_of_2.emplace_back(mul);
        goods.emplace(mul);
        mul = mul * 2;
    }
    for (ll& x : power_of_2) {
        dfs(x);
    }
    int N;
    cin >> N;
    vector<ll> res(goods.begin(), goods.end());
    cout << res[N-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}