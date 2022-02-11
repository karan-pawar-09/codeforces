/*
    author:Karan
    created:01.02.2022 19:52:15
*/
#if true
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define endl '\n'
#define mset(a, x) memset(a, x, sizeof(a))
#endif

int maxdepth;

void dfs(int x, vector<vector<int>> &graph, vector<vector<pair<int, int>>> &Q, vector<vector<int>> &tree, vector<int> &ans)
{
    for (int d = 0; d <= maxdepth; d++)
        tree[d][x >> d]++;

    for (auto a : Q[x])
    {
        int e = a.first;
        int index = a.second;

        int val = 0;
        for (int d = maxdepth - 1; d >= 0; d--)
        {
            int val2 = val + (1 << d);
            if (tree[d][(e ^ val2) >> d] > 0)
                val = val2;
        }
        ans[index] = val;
    }

    for (int y : graph[x])
        dfs(y, graph, Q, tree, ans);

    for (int d = 0; d <= maxdepth; d++)
        tree[d][x >> d]--;
}

vector<int> xorQuery(vector<int> B, vector<int> D, vector<int> E)
{

    int n = B.size() + 1;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
        graph[B[i]].push_back(i + 2);

    int num_query = D.size();
    vector<vector<pair<int, int>>> Q(n + 1);
    for (int i = 0; i < num_query; i++)
        Q[D[i]].push_back({E[i], i});

    vector<int> ans(num_query);

    int p2 = 2;
    maxdepth = 1;
    while (p2 <= n)
    {
        p2 *= 2;
        maxdepth++;
    }

    vector<vector<int>> tree(maxdepth + 1);
    for (int d = 0; d <= maxdepth; d++)
        tree[d] = vector<int>((p2 >> d) + 1, 0);

    dfs(1, graph, Q, tree, ans);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m), c(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    vector<int> ans = xorQuery(a, b, c);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}