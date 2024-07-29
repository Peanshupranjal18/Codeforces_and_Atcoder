#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree
{
    vector<ll> tree;
    int n;

private:
    void buildTree(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = 0;
            return;
        }
        int mid = (start + end) / 2;
        buildTree(2 * node, start, mid);
        buildTree(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    ll queryTree(int node, int start, int end, int left, int right)
    {
        if (left > end || right < start)
            return 0;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        ll leftSum = queryTree(2 * node, start, mid, left, right);
        ll rightSum = queryTree(2 * node + 1, mid + 1, end, left, right);
        return leftSum + rightSum;
    }

    void updateTree(int node, int start, int end, int index, ll value)
    {
        if (start == end)
        {
            tree[node] += value;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
            updateTree(2 * node, start, mid, index, value);
        else
            updateTree(2 * node + 1, mid + 1, end, index, value);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * n, 0);
        buildTree(1, 0, n - 1);
    }

    ll query(int left, int right)
    {
        return queryTree(1, 0, n - 1, left, right);
    }

    void update(int index, ll value)
    {
        updateTree(1, 0, n - 1, index, value);
    }
};

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    SegmentTree segTree(n + 1);
    vector<ll> result(n);

    for (ll i = 0; i < n; i++)
    {
        result[i] = segTree.query(v[i] + 1, n);
        segTree.update(v[i], 1);
    }

    for (ll i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    solve();
    return 0;
}