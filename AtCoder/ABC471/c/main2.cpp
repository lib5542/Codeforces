#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    ll cur = 0;

    for (int i = 1; i < N; i++) {
        if (abs(A[i]) < abs(A[cur])) {
            cur = i;
        }
    }

    int left = cur-1;
    int right = cur+1;

    ll res = 0;
    res += abs(A[cur]);

    while (left != -1 || right != N) {

        if (left == -1 && right != N) {
            res += abs(A[cur]-A[right]);
            cur = right;
            right++;
        } else if (right == N && left != -1) {
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