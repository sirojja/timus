#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, l, a, b;
    stack <pair <int, int> > st;
    vector <pair <int, int> > t;
    vector <pair <int, int> > v;
    map <pair<int, int>, int> mp;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        t.push_back(make_pair(a, 0));
        t.push_back(make_pair(b, 2));
        v.push_back(make_pair(a, b));
        mp[make_pair(a, b)] = i + 1;
    }
    cin >> l;
    for(int i = 0; i < l; i++) {
        cin >> a;
        t.push_back(make_pair(a, 1));
    }
    sort(t.begin(), t.end());
//    std::vector<pair <int, int> >::iterator it;
//    it = unique (t.begin(), t.end());
//    t.resize( std::distance(t.begin(),it) );
    int kb = 0;
//    for (int i = 0; i < t.size(); i++)
//        cout << t[i].first << " " << t[i].second << endl;
    for(int i = 0; i < t.size(); i++) {
        if(t[i].second == 1) {
            if(st.empty())
                cout << -1 << endl;
            else {
                cout << mp[st.top()] << endl;
            }
        }
        if(t[i].second == 0) {
            st.push(v[kb]);
            kb++;
        }
        if(t[i].second == 2)
            st.pop();
    }


    return 0;
}
