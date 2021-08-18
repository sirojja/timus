#include <bits/stdc++.h>

using namespace std;

struct segment {
    int l, r, id;
};

bool cmp(const segment x, const segment y) {
    return ((x.r - x.l) < (y.r - y.l));
}
vector <segment> segments (1001);
int dp[501], parent[501], ans[501];

int main(){
    int n, a, b;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        if(a > b)
            swap(a, b);
        segments[i].l = a;
        segments[i].r = b;
        segments[i].id = i;
    }
    sort(segments.begin() + 1, segments.begin() + n + 1, cmp);
    int x = 1, ans_k = 1;
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = 1;
        for(int j = 1; j < i; j++) {
            if(segments[i].l  < segments[j].l && segments[j].r < segments[i].r && dp[j] + 1 > dp[i] ) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
                if(dp[i] > ans_k){
                    ans_k = dp[i];
                    x = i;
                }
            }
        }
    }
    int j = 0;
    while(true) {
        ans[j] = segments[x].id;
        x = parent[x];
        j++;
        if(x == 0)
            break;
    }
    cout << ans_k << endl;
    for(int i = j - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}
