#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int> > g[100];
int dp[100][100];



int dfs(int vertex, int parent, int q) {
    int cnt = 0;
    for(int i = 0; i < g[vertex].size(); i++) {
        int next = g[vertex][i].first;
        int d = g[vertex][i].second;
        if(next != parent) {
            cnt += dfs(next, vertex, q) + 1;
            for(int j = min(cnt, q); j > 0; j--) {
                for(int k = min(cnt, j); k > 0; k--)
                    dp[vertex][j] = max(dp[vertex][j], dp[vertex][k - 1] + dp[next][j - k] + d);
            }
        }
    }
    return cnt;
}

int main()
{
    int n, q, u, v, d;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v >> d;
        u--;
        v--;
        g[u].push_back(make_pair(v, d));
        g[v].push_back(make_pair(u, d));
    }
    dfs(0, -1, q);
    cout << dp[0][q];
    return 0;
}
