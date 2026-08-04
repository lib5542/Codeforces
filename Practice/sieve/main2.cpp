#include <bits/stdc++.h>

using namespace std;

// n이하의 소수 모두 출력
vector<int> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= n; j += i) is_prime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 0; i <= n; i++) {
        if (is_prime[i]) primes.emplace_back(i);
    }
    return primes;
}

int main() {
    vector<int> primes = sieve(127);
    for (const int& p : primes) cout << p << " ";
    return 0;
}