#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<vector<int>> C;
    for (int i = 0; i < N/10; i++) {
        vector<int> temp(10);
        for (int j = 0; j < 10; j++) {
            cin >> temp[j];
        }
        sort(temp.begin(), temp.end());
        C.emplace_back(temp);
    }
    vector<int> temp;
    for (int i = 0; i < N%10; i++) {
        int x;
        cin >> x;
        temp.emplace_back(x);
    }
    sort(temp.begin(), temp.end());
    C.emplace_back(temp);

    int i = 1;
    while (i <= N) {
        if (i != C[(i-1)/10][(i-1)%10]) {
            cout << "No";
            return;
        }
        ++i;
    }
    cout << "Yes";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}