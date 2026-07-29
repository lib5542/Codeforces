#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll N;
    cin >> N;

    vector<string> pow2;
    ll p = 1;
    while (p <= 1000000000LL) {
        pow2.push_back(to_string(p));
        p *= 2;
    }

    set<ll> good;
    queue<ll> q;

    for (const string& s : pow2) {
        ll val = stoi(s);
        good.insert(val);
        q.push(val);
    }

    while (!q.empty()) {
        string cur = to_string(q.front());
        q.pop();

        for (const string& p : pow2) {
            string new_good = cur + p;
            if (new_good.size() > 10) continue;

            ll new_good_num = stoll(new_good);

            if (new_good_num <= 1000000000LL) {
                if (good.find(new_good_num) == good.end()) {
                    good.insert(new_good_num);
                    q.push(new_good_num);
                }
            }
        }
    }

    vector<ll> good_vec(good.begin(), good.end());
    cout << good_vec[N-1] << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}