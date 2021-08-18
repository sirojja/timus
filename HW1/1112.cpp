#include <bits/stdc++.h>

using namespace std;



int main() {
    int n, a, b;
    vector <pair <int, int> > v;
    vector <pair <int, int> > ans;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        v.push_back(make_pair(b,a));
    }
    sort(v.begin(),v.end());
    int p = -1e6;
    for (int i = 0; i < v.size(); i++) {
        if(v[i].second >= p) {
            p = v[i].first;
            ans.push_back(make_pair(v[i].second,p));
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
