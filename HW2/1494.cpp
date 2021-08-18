#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    stack <int> st;
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    int j = 0;
    for(int i = 0; i < n; i++) {
        st.push(i + 1);
        while(!st.empty() && st.top() == v[j]) {
            st.pop();
            j++;
            }
        }

    if(!st.empty())
        cout << "Cheater";
    else
         cout << "Not a proof";
    return 0;
}
