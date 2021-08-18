#include <bits/stdc++.h>

using namespace std;



int main() {
    int m, l, r;
    vector <pair <int, int> > v;
    vector <pair <int, int> > ans;
    cin >> m;
    while(true) {
        cin >> l >> r;
        if(l == 0 && r == 0)
            break;
        //if(l < m && r > 0)
            v.push_back(make_pair(l, r));
    }
//    if(v.size() == 0 || v[(v.size()) - 1].second < m) {
//        cout << "No solution";
//        return 0;
//    }
//    for(int i = 0; i < v.size(); i++)
//        cout << v[i].first << " " << v[i].second << endl;
    sort(v.begin(), v.end());
    if(v[(v.size()) - 1].second < m) {
        cout << "No solution";
        return 0;
    }
    int tmp = 0, mx = 0;
    pair <int, int> tmpm = v[0];

    for(int i = 0; i < v.size(); i++) {
        if (v[i].first > tmp) {
            if(mx < v[i].first) {
                cout << "No solution";
                return 0;
            }
            ans.push_back(tmpm);
            tmp = mx;
        }

        if(v[i].second > mx) {
            mx = v[i].second;
            tmpm = v[i];
        }
        if(mx >= m) {
            ans.push_back(v[i]);
            break;
        }
    }
    cout << ans.size() << endl;
//    for(int i = 0; i < ans.size() - 1; i++) {
//        if(v[i + 1].first > v[i].second) {
//            cout << "No solution";
//            return 0;
//        }
//    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
//    for(int i = 0; i < v.size(); i++)
//        cout << v[i].first << " " << v[i].second << endl;
    return 0;
}
