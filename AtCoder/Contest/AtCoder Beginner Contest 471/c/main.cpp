#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    A.emplace_back(LLONG_MAX);
    A.emplace_back(LLONG_MIN);

    sort(A.begin(), A.end());

    ll temp = A[0];
    ll cur = 0;
    for (int i = 1; i <= N; i++) {
        if (abs(A[i]) <= abs(temp)) {
            if (abs(A[i]) == abs(temp)) {
                if (A[i] < temp) {
                    temp = A[i];
                    cur = i;
                }
            } else {
                temp = A[i];
                cur = i;
            }
        }
    }

    ll left = cur-1;
    ll right = cur+1;

    ll res = 0;
    res += abs(A[cur]);

    while (A[left] != LLONG_MIN && A[right] != LLONG_MAX) {
        left = cur - 1;
        right = cur + 1;

        if (A[left] == LLONG_MIN) {
            res += abs(A[cur]-A[right]);
            cur = right;
            right++;
        } else if (A[right] == LLONG_MAX) {
            res += abs(A[cur]-A[left]);
            cur = left;
            left--;
        } else {
            if (abs(A[cur]-A[left]) <= abs(A[cur]-A[right])) {
                res += abs(A[cur]-A[left]);
                cur = left;
                left--;
            } else {
                res += abs(A[cur]-A[right]);
                cur = right;
                right++;
            }
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