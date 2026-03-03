#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve_guaranteed_ac(){
    ll x, y;
    if (!(cin >> x >> y)) return; 

    // Step 1: Check for Feasibility (y must be divisible by x)
    if (y % x != 0) {
        cout << 0 << "\n";
        return;
    }

    // Step 2: Calculate the Reduced Product N = y/x
    // N is the product A * B, where gcd(A, B) = 1
    ll N = y / x; 
    
    // If N=1, the only pair (A,B) is (1,1). gcd(1,1)=1. Solution count is 1 pair.
    if (N == 1) {
        cout << 1 << "\n";
        return;
    }

    // Step 3: Count the number of distinct prime factors (k) of N
    int distinct_prime_factors = 0;
    ll temp_N = N;

    // Check for prime factor 2
    if (temp_N % 2 == 0) {
        distinct_prime_factors++;
        while (temp_N % 2 == 0) {
            temp_N /= 2;
        }
    }

    // Check for odd prime factors (from 3 upwards)
    for (ll i = 3; i * i <= temp_N; i += 2) {
        if (temp_N % i == 0) {
            distinct_prime_factors++;
            while (temp_N % i == 0) {
                temp_N /= i;
            }
        }
    }

    // Step 4: Handle the remaining factor (if temp_N > 1, it's a prime itself)
    if (temp_N > 1) {
        distinct_prime_factors++;
    }

    // Step 5: The total number of solutions is 2^k
    // Total pairs (A, B) = 2^(number of distinct prime factors of N)
    ll ans = 1LL << distinct_prime_factors; 
    
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1; 
    // If the problem had multiple test cases, you'd loop here.
    while(t--) solve_guaranteed_ac(); 
    return 0;
}