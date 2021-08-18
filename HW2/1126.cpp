#include <bits/stdc++.h>

using namespace std;

int main() {
    int m = -1e5, x = -2, c, k;
    int n;
    cin >> n;
    multiset <int> s;
    vector <int> v;
    for(int i = 0; i < n; i++) {
        cin >> c;
        v.push_back(c);
        s.insert(c);
    }
//    for(auto l : s)
//        cout << l << " ";
//    cout << endl;
    vector <int> ans;
    auto it = s.end();
    it--;
    m = *it;
   // cout << m << endl;
    ans.push_back(m);

    int  i = 0;
    while (true) {
        cin >> x;
        if(x == -1)
            break;

        s.erase(s.find(v[i]));
        i++;

        v.push_back(x);
        s.insert(x);
//        for(auto l : s)
//            cout << l << " ";
//        cout << endl;
        it = s.end();
        it--;
        m = *it;
        //cout << m << endl;
        ans.push_back(m);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;


    return 0;
}
