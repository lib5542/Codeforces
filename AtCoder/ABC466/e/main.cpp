#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<int> greedy;
    int counter = 0;
    
    for (int i = 0; i < N; i++) {
        if (A[i] <= B[i]) {
            counter += B[i]-A[i];
        } else {
            if (counter != 0) {
                greedy.push_back(counter);
                counter = 0;
            }
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}