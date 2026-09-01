#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {

    ll N;
    cin >> N;

    vector<ll> powers;
    ll power_num = 1;
    while (power_num <= 1000000000LL) {
        powers.push_back(power_num);
        power_num *= 2;
    }

    queue<ll> good_numbers;
    set<ll> result;
    for (const ll& p : powers) {
        good_numbers.emplace(p);
        result.insert(p);
    }

    while (!good_numbers.empty()) {
        ll cur = good_numbers.front();
        good_numbers.pop();

        for (const ll& p : powers) {
            string new_string = to_string(cur)+to_string(p);
            if (new_string.size() < 11) {
                ll new_ll = stoll(new_string);
                if (new_ll <= 1000000000LL && result.find(new_ll) == result.end()) {
                    result.emplace(new_ll);
                    good_numbers.emplace(new_ll);
                }
            }
        }
    }
    vector<ll> res(result.begin(), result.end());
    cout << res[N-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}