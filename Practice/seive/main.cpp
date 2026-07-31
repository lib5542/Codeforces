#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<bool> is_prime(N+1, true);
    vector<int> primes;
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i*i <= N; i++) {
        if (is_prime[i] == true) {
            for (int j = i*i; j <= N; j += i) is_prime[j] = false;
        }
    }

    for (int j = 0; j <= N; j++) {
        if (is_prime[j] == true) primes.push_back(j);
    }

    for (const int& prime : primes) cout << prime << " ";

    return 0;
}