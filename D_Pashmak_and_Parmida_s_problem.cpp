// this question uses the same concept as the previously solved question
// enemy is weak

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define ll long long
#define vl vector<ll>
#define pb push_back

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// template for fenwick Tree (Binary Indexed Tree)

class FenwickTree
{
public:
    vector<ll> bit;
    ll n;

    FenwickTree(ll n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    void update(ll idx, ll delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
        {
            bit[idx] += delta;
        }
    }

    ll query(ll idx)
    {
        ll sum = 0;
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1)
        {
            sum += bit[idx];
        }
        return sum;
    }

    ll query(ll l, ll r)
    {
        return query(r) - query(l - 1);
    }
};

void solve()
{
    ll n;
    cin >> n;
    vl v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    map<ll, ll> freqLeft, freqRight;
    vl leftCount(n), rightCount(n);

    for (ll i = 0; i < n; i++)
    {
        freqLeft[v[i]]++;
        leftCount[i] = freqLeft[v[i]];
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        freqRight[v[i]]++;
        rightCount[i] = freqRight[v[i]];
    }

    ll maxFreq = *max_element(leftCount.begin(), leftCount.end());
    FenwickTree fenwickTree(maxFreq + 1);

    ll result = 0;
    for (ll i = n - 1; i > 0; i--)
    {
        fenwickTree.update(rightCount[i], 1);
        result += fenwickTree.query(0, leftCount[i - 1] - 1);
    }

    cout << result << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // auto start = high_resolution_clock::now();

    solve();

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() * 1e-9 << " s\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;
vector<vector<ll>> adj;
vector<ll> vis;
vector<ll> cats;

ll dfs(ll node, ll cat_count)
{
    vis[node] = 1;

    if (cats[node] == 1)
    {
        cat_count++;
    }
    else
    {
        cat_count = 0;
    }

    if (cat_count > m)
    {
        return 0;
    }

    bool isLeaf = true;
    ll cnt = 0;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            isLeaf = false;
            cnt += dfs(it, cat_count);
        }
    }

    if (isLeaf)
    {
        return 1;
    }

    return cnt;
}

void solve()
{
    cin >> n >> m;

    cats.resize(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> cats[i];
    }

    adj.resize(n + 1);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis.resize(n + 1, 0);

    ll ans = dfs(1, 0);
    cout << ans << "\n";
    return;
}

signed main()
{
    solve();
    return 0;
}