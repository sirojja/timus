#include <bits/stdc++.h>

using namespace std;

int n, l, m;
vector<pair<int,int> > g[1000000];
int tin[1000000], tout[1000000], d[1000000];
int up[1000000][20];

int timer;


void dfs (int v, int p = 0, int length = 0)
{
    int i, to;
    tin[v] = timer++;
    up[v][0] = p;
    d[v] = length;
    for(i = 1; i <= l; i++)
        up[v][i] = up[up[v][i-1]][i-1];
    for(i = 0; i < g[v].size(); i++)
    {
        to = g[v][i].first;
        if (to != p) dfs (to, v, length + g[v][i].second);
    }
    tout[v] = timer++;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int main() {
    cin >> n;
    l = 1;
    while ((1 << l) <= n)
        ++l;
    int u, v, w;
    for(int i = 0; i < n - 1; i++) {
       cin >> u >> v >> w;
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }

    dfs(0);

    cin >> m;
    int LCA;
    vector <int> ans;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        LCA = lca(u, v);
        ans.push_back(d[u] + d[v] -  2 * d[LCA]);
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;


    return 0;
}
