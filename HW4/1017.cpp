#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main() {
    long long n;
    cin >> n;
    vector <long long> dp(501, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for(int j = n; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }
    dp[n]--;
    cout << dp[n];
    return 0;
}

