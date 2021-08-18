#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long n, k;
    cin >> n >> k;
    n++;
    k--;
    long long f[n];
    f[0] = 0;
    f[1] = k;
    for(int i = 2; i < n; i++)
        f[i] = (f[i - 1] + f[i - 2]) * k;
    cout << f[n - 1] + f[n - 2];
    return 0;
}
