#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long n;
    cin >> n;
    vector <long long> f (n + 1, 1e7);
    f[0] = 0;
        for(int k = 1; k <= n; k++) {
        for(int i = 1; i*i <= k; ++i)
            f[k] = min(f[k], f[k - i*i] + 1);
    }
    cout << f[n];

    return 0;
}
