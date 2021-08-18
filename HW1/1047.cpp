#include <bits/stdc++.h>

using namespace std;



int main() {
    int n;
    cin >> n;
    double a0, an1,x, c = 0;
    cin >> a0 >> an1;
    for(int i = 0; i < n; i++) {
        cin >> x;
        c += (n - i)*x;
    }
    c *=2;
    a0 = (an1 + n*a0 - c)/(n + 1);
    printf("%.2f",a0);
    return 0;
}
