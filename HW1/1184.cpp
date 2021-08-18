#include <bits/stdc++.h>

using namespace std;

int f(vector <int> v, int l) {
    int k = 0;
    for(int i = 0; i < v.size(); i++)
        k += (v[i] / l);
    return k;
}

int main() {
    int n, s;
    double x;
    long long chk = 0;
    cin >> n >> s;
    vector <int> v;
    int y;
    for (int i = 0; i < n; i++) {
        cin >> x;
        y = ceil(x*100);
        x *= 100;
        v.push_back(y);
        chk += y;

    }

    if(chk < s) {
        cout << "0.00";
        return 0;
    }
    int l = 200;
    long long lb = 1, rb = 1e9;
    int k = rb;

    long long m;
    while(rb - lb > 1) {
        m = (rb + lb)/2;
        if(f(v, m) >= s)
            lb = m;
        else
            rb = m;
    }
    //cout << lb << endl;

    if(f(v, rb) >= s) {
            double ans = 1.0 * rb / 100;
            printf("%.2f\n", ans);
        }
        else {
             double ans = 1.0 * lb / 100;
             printf("%.2f\n", ans);
        }
    //cout << endl << rb << endl;
    //cout << f(v, 201);

    return 0;
}
