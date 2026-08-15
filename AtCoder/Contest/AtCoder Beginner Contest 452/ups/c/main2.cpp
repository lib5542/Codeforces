#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<pair<int, int>> inp(N);
    for (int i = 0; i < N; i++) {
        cin >> inp[i].first >> inp[i].second;
    }

    int M;
    cin >> M;

    set<tuple<char, int, int>> mem;
    vector<string> inp_list;

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        inp_list.emplace_back(s);

        for (int j = 0; j < s.size(); j++) {
            mem.emplace(s[j], j+1, s.size());
        }
    }

    for (int i = 0; i < M; i++) {
        string s;
        s = inp_list[i];

        if (s.size() < N) {
            cout << "No\n";
            continue;
        }

        bool res = true;
        for (int j = 0; j < s.size(); j++) {
            if (mem.find(tuple(s[j], inp[j].second, inp[j].first)) == mem.end()) {
                res = false;
                break;
            }
        }
        if (res) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}