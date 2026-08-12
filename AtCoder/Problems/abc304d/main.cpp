#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int my_binarySearch(vector<ll>& a, ll x) {
    ll left = 0;
    ll right = a.size()-1;
    ll ans = -1;

    while (left <= right) {
        ll mid = left + (right-left)/2;
        if (a[mid] <= x) {
            ans = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return ans+1;
}

void solve() {
    ll W, H;
    cin >> W >> H;

    int N;
    cin >> N;

    vector<pair<ll, ll>> pos(N);

    for (int i = 0; i < N; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    ll A;
    cin >> A;

    vector<ll> a(A);
    for (int i = 0; i < A; i++) cin >> a[i];

    ll B;
    cin >> B;

    vector<ll> b(B);
    for (int i = 0; i < B; i++) cin >> b[i];

    map<pair<ll, ll>, ll> m;

    for (int i = 0; i < N; i++) {
        ll st_x = pos[i].first;
        ll st_y = pos[i].second;

        ll sq_pos_x = my_binarySearch(a, st_x);
        ll sq_pos_y = my_binarySearch(b, st_y);

        m[pair(sq_pos_x, sq_pos_y)]++;
    }

    auto st_max_it = max_element(m.begin(), m.end(), [](const auto& a, const auto& b) -> bool {
        return a.second < b.second;
    });

    ll st_max = st_max_it->second;

    auto st_min_it = min_element(m.begin(), m.end(), [](const auto& a, const auto& b) -> bool {
        return a.second < b.second;
    });

    ll st_min = st_min_it -> second;
    if (m.size() < (A+1)*(B+1)) st_min = 0;

    cout << st_min << " " << st_max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}