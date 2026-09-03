#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000000;


int axis[MAX+1];

void solve() {

    int i = 1;
    int counter = 1;
    int flag = 1;
    vector<int> first_red;

    while (i <= MAX) {
        for (int j = 0; j < counter; j++) {
            if (flag) axis[i] = 1;
            i++;
            if (i > MAX) break;
        }
        if (flag == 1) flag = 0;
        else {
            flag = 1;
            first_red.emplace_back(i);
        }
        counter++;
    }

    // axis: 1 - red, 0 - black

    int n;
    cin >> n;

    vector<int> pos(n);

    for (int i = 0; i < n; i++) cin >> pos[i];

    int res_num = 0;

    while (true) {
        int max_dist = -1;
        bool res = true;
        for (int i = 0; i < n; i++) {
            if (axis[pos[i]] == 0) {
                int dist = *upper_bound(first_red.begin(), first_red.end(), pos[i]) - pos[i];
                max_dist = max(max_dist, dist);
                res = false;
            }
        }
        if (res) break;
        for (int i = 0; i < n; i++) {
            pos[i] += max_dist;
        }
        res_num += max_dist;
    }

    cout << res_num;

}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}