#include <bits/stdc++.h>

using namespace std;



int main() {
    long long n, x;
    cin >> n;
    vector <long long> v;
    vector <int> ans;
    map<long long, set <long long>> m;
    for(int i =  0; i < n; i++) {
        cin >> x;
        m[x].insert(i);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    long long k, l, r;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> l >> r >> x;
        l--;
        r--;
        if(binary_search(v.begin(),v.end(),x)) {
            if(*m[x].lower_bound(l) >= l && *m[x].lower_bound(l) <= r && m[x].count(*m[x].lower_bound(l)) != 0 )
                    ans.push_back(1);
                else
                    ans.push_back(0);

        }
        else {
            ans.push_back(0);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
//    cout << endl << *m[5].lower_bound(2) << endl;
//    for(auto i : m[5])
//        cout << i << " ";
    return 0;
}
