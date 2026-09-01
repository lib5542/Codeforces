#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    int counter = 0;
    int pointer1 = 1;
    int pointer2 = 2;

    while (true) {
        cout << "? " << pointer1 << " " << pointer2 << endl;
        string answer;
        cin >> answer;
        if (answer == "Yes") {
            counter += (pointer2-pointer1);
            if (pointer2 == N) break;
            pointer2 += 1;
        } else {
            if (pointer1 == N-1 && pointer2 == N) break;
            pointer1 += 1;
            if (pointer1 == pointer2) pointer2 += 1;
        }
    }
    cout << "! " << counter << endl;

}

int main() {
    solve();

    return 0;
}